#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
int main() {
  int n;
  char a[50], b[50];
  cin >> n;
  double temp, sum = 0.0;
  int t = 0;
  for(int i = 0; i < n; i++) {
    cin >> a;
    sscanf(a, "%lf", &temp);
    sprintf(b, "%.2lf", temp);
    int flag = 0;
    for(int j = 0; j < strlen(a); j++) {
      if(a[j] != b[j])
        flag = 1;
    }
    if(flag == 1 || temp < -1000 || temp > 1000) {
      printf("ERROR: %s is not a legal number\n", a);
      continue;
    }
    t++;
    sum += temp;
  }

  if(t == 0) {
    printf("The average of 0 numbers is Undefined");
  }
  else if(t == 1){
    printf("The average of 1 number is %.2lf", sum);
  }
  else {
    printf("The average of %d numbers is %.2lf", t, sum / t);
  }
  return 0;
}
