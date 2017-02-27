#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
  long long int id;
  int score, rank, location, localrank;
};
bool cmp(node a, node b) {
  if(a.score != b.score)
    return a.score > b.score;
  else
    return a.id < b.id;
}
vector<node> v;
int main() {
  int n, k;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &k);
    vector<node> temp(k);
    for(int j = 0; j < k; j++) {
      scanf("%lld %d", &temp[j].id, &temp[j].score);
      temp[j].location = i;
    }
    sort(temp.begin(), temp.end(), cmp);
    temp[0].localrank = 1;
    v.push_back(temp[0]);
    for(int j = 1; j < k; j++) {
      if(temp[j].score == temp[j - 1].score)
        temp[j].localrank = temp[j - 1].localrank;
      else
        temp[j].localrank = j + 1;
      v.push_back(temp[j]);
    }
  }
  sort(v.begin(), v.end(), cmp);
  v[0].rank = 1;
  for(int i = 1; i < v.size(); i++) {
    if(v[i].score == v[i -1].score)
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
