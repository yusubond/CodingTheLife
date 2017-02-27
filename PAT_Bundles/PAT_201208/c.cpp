#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
#include <vector>
using namespace std;
struct node {
  char name[5];
  vector<int> course;
};
bool cmp(int a, int b) {
  return a < b;
}
vector<node> stu;
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for(int i = 0; i < k; i++) {
    int id, tempnum;
    char tempname[5];
    scanf("%d %d", &id, &tempnum);
    for(int j = 0; j < tempnum; j++) {
      cin >> tempname;
      int flag = 0;
      for(int k = 0; k < stu.size(); k++) {
        if(strcmp(stu[k].name, tempname) == 0) {
          stu[k].course.push_back(id);
          flag = 1;
          break;
        }
      }
      if(flag == 0) {
        struct node tempnode;
        strcpy(tempnode.name, tempname);
        tempnode.course.push_back(id);
        stu.push_back(tempnode);
      }
    }
  }
  for(int i = 0; i < stu.size(); i++)
    sort(stu[i].course.begin(), stu[i].course.end(), cmp);
  for(int i = 0; i < n; i++) {
    char checkname[5];
    cin >> checkname;
    int flag1 = 0;
    for(int j = 0; j < stu.size(); j++) {
      if(strcmp(stu[j].name, checkname) == 0) {
        printf("%s %d", stu[j].name, stu[j].course.size());
        for(int t = 0; t < stu[j].course.size(); t++) {
          printf(" %d", stu[j].course[t]);
        }
        printf("\n");
        flag1 = 1;
      }
    }
    if(flag1 == 0)
      printf("%s 0\n", checkname);
  }
  return 0;
}
