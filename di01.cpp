#include <iostream>
#include <vector>
using namespace std;
void find(vector<vector<bool> >& v, int x, int y){
  int row = v.size();
  int column = v[0].size();
  if((x < 0) || (y < 0) || (x >= row) || (y >= column) || !v[x][y])
      return;
  v[x][y] = false;
  find(v, x - 1, y);
  find(v, x, y - 1);
  find(v, x + 1, y);
  find(v, x, y + 1);
}
int lands(vector<vector<bool> >& v) {
  if(v.empty() || v[0].empty())
      return 0;
  int row = v.size(), column = v[0].size();
  int result = 0;
  for(int i = 0; i < row; i++){
      for(int j = 0; j < column; j++){
          if(v[i][j]){
             result += 1;
             find(v, i, j);
          }
      }
  }
  return result;
}
int main() {
  int n, m, t;
  cin >> n >> m;
  vector<vector<bool> > v;
  v.resize(n);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> t;
      if(t == 1)
        v[i].push_back(true);
      else
        v[i].push_back(false);
    }
  }
  cout << lands(v) << endl;
  return 0;
}
