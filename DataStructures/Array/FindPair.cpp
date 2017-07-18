#include <iostream>
#include <vector>
using namespace std;

struct Node {
  int val;
  vector<int> key;
};
void FindPair(int array[], int n, int sum) {
  Node res[sum+1];
  int i;
  for(i = 0; i <= sum; i++) {
    res[i].val = -1;
  }
  i = 0;
  while(i < n) {
    if(array[i] > sum) {
      i++;
    } else {
      if(res[sum - array[i]].val == array[i]) {
        for(int j = 0; j < res[sum - array[i]].key.size(); j++) {
          cout << "(" << res[sum - array[i]].key[j] << "," << i << ")" << endl;
        res[array[i]].val = sum - array[i];
        res[array[i]].key.push_back(i);
        }
      } else {
        res[array[i]].val = sum - array[i];
        res[array[i]].key.push_back(i);
      }
      i++;
    }
  }
}

int main() {
  int n, sum, temp;
  cin >> n >> sum;
  int data[n];
  for(int i = 0; i < n; i++) {
    cin >> temp;
    data[i] = temp;
  }
  FindPair(data, n, sum);
  return 0;
}
