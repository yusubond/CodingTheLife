#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
struct node {
  int poptime;
  int endtime;
  queue<int> q;
};
int main() {
  int n, m, k, q;
  scanf("%d %d %d %d", &n, &m, &k, &q);
  vector<int> time(k + 1), result(k + 1);
  for(int i = 1; i <= k; i++)
    scanf("%d", &time[i]);
  vector<node> window(n + 1);
  vector<bool> sorry(k + 1, false);
  int index = 1;
  //第一步，先填充N * M
  for(int i = 1; i <= m; i++) {    //队列长度，视为行
    for(int j = 1; j <= n; j++) {  //窗口数，视为列
      if(index <= k) {
        //起始值
        if(i == 1)
          window[j].poptime = window[j].endtime;
        //将时间值压入队列
        window[j].q.push(time[index]);
        if(window[j].endtime >= 540)
          sorry[index] = true;
        //计算endtime
        window[j].endtime += time[index];
        result[index] = window[j].endtime;
        index++;
      }
    }
  }
  //第二步，处理超出部分
  while(index <= k) {
    int tempmin = window[1].poptime, tempwindow = 1;
    //选取poptime最小的窗口
    for(int i = 2; i <= n; i++) {
      if(window[i].poptime < tempmin) {
        tempwindow = i;
        tempmin = window[i].poptime;
      }
    }
    //最小窗口，队头出列
    window[tempwindow].q.pop();   //队头出列
    window[tempwindow].q.push(time[index]);  //新值入队
    window[tempwindow].poptime += window[tempwindow].q.front();  //更新poptime
    if(window[tempwindow].endtime >= 540)
      sorry[index] = true;
    window[tempwindow].endtime += time[index];  //更新endtime
    result[index] = window[tempwindow].endtime;
    index++;
  }
  for(int i = 1; i <= q; i++) {
    int query, minute;
    scanf("%d", &query);
    minute = result[query];
    if(sorry[query] == true)
      printf("Sorry\n");
    else
      printf("%02d:%02d\n",(minute + 480) / 60, (minute + 480) % 60);
  }
  return 0;
}
