#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <string.h>
using namespace std;
bool cmp(int a, int b) {
  return a > b;
}
int main() {
  int n, m, temp;
  while(scanf("%d %d", &n, &m) != EOF) {
    int minp = 0, maxp = 0;
    vector<int> price;
    vector<int> num;
    for(int i = 0; i < n; i++) {
      scanf("%d", &temp);
      price.push_back(temp);
    }
    sort(price.begin(), price.end());
    map<string, int> item_count;
    string item;
    for(int i = 0; i < m; i++) {
      getline(cin, item);
      item_count[item]++;
    }
    for(map<string, int>::iterator it = item_count.begin(); it != item_count.end(); it++) {
      num.push_back(it->second);
      printf("%s %d\n", it->first.c_str(), it->second);
    }
    sort(num.begin(), num.end(), cmp);
    for(int i = 0; i < num.size(); i++) {
      printf("%d ", num[i]);
      minp += num[i] * price[i];
      maxp += num[i] * price[price.size() - 1 - i];
    }
    //printf("%d %d\n", minp, maxp);
    price.clear();
    num.clear();
    item_count.clear();
  }
}
