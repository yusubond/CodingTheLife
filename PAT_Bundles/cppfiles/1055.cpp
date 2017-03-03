#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string.h>
using namespace std;
struct node {
  char name[10];
  int age;
  long long int worth;
};
bool cmp(node a, node b) {
  if(a.worth != b.worth)
    return a.worth > b.worth;
  else if(a.age != b.age)
    return a.age < b.age;
  else
    return strcmp(a.name, b.name) < 0;
}
int n,k;
vector<int> book(210, 0);
vector<node> person;
vector<node> v;
int main() {
  scanf("%d %d", &n, &k);
  person.resize(n);
  int tempage;
  long long int tempworth;
  char tempname[10];
  for(int i = 0; i < n; i++) {
    cin >> tempname >> tempage >> tempworth;
    strcpy(person[i].name, tempname);
    person[i].age = tempage;
    person[i].worth = tempworth;
  }
  sort(person.begin(), person.end(), cmp);
  for(int i = 0; i < n; i++) {
    if(book[person[i].age] < 100) {
      v.push_back(person[i]);
      book[person[i].age]++;
    }
  }
  for(int i = 0; i < k; i++) {
    vector<node> tempk;
    int sum, minage, maxage;
    scanf("%d %d %d", &sum, &minage, &maxage);
    for(int j = 0; j < n; j++) {
      if(v[j].age >= minage && v[j].age <= maxage) {
        tempk.push_back(v[j]);
      }
    }
    sort(tempk.begin(), tempk.end(), cmp);
    printf("Case #%d:\n", i + 1);
    if(sum > tempk.size())
      sum = tempk.size();
    if(tempk.size() == 0) {
      printf("None\n");
    } else {
      for(int j = 0; j < sum; j++) {
        cout << tempk[j].name << " " << tempk[j].age << " " << tempk[j].worth << endl;
      }
    }
    tempk.clear();
  }
  return 0;
}
