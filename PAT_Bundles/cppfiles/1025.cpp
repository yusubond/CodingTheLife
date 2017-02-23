#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
  long long int id;
  int grade, location, rank, localrank;
};
vector<node> v;
bool cmp(node a, node b) {
  if(a.grade != b.grade)
    return a.grade > b.grade;
  else
    return a.id < b.id;
}
int main() {
  int N, temp, grade;
  long long int id;
  scanf("%d", &N);
  for(int i = 1; i <= N; i++) {
    scanf("%d", &temp);
    vector<node> tempv(temp);
    for(int j = 0; j < temp; j++) {
      cin >> id >> grade;
      tempv[j].id = id;
      tempv[j].grade = grade;
      tempv[j].location = i;
    }
    sort(tempv.begin(), tempv.end(), cmp);
    tempv[0].localrank = 1;
    for(int k = 1; k < temp; k++) {
      if(tempv[k].grade == tempv[k - 1].grade)
        tempv[k].localrank = tempv[k - 1].localrank;
      else
        tempv[k].localrank = k + 1;
    }
    for(int t = 0; t < temp; t++) {
      v.push_back(tempv[t]);
    }
  }
  sort(v.begin(), v.end(), cmp);
  v[0].rank = 1;
  for(int i = 1; i < v.size(); i++) {
    if(v[i].grade == v[i - 1].grade)
      v[i].rank = v[i - 1].rank;
    else
      v[i].rank = i + 1;
  }
  printf("%d\n", v.size());
  for(int i = 0; i < v.size(); i++) {
    printf("%013lld %d %d %d\n", v[i].id, v[i].rank, v[i].location, v[i].localrank);
  }
  return 0;
}
