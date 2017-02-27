#include <cstdio>
#include <string.h>
using namespace std;
int count[10];
int main() {
  char num[25];
  int flag = 0, flag1 = 0;
  //int count[10];
  scanf("%s", num);
  for(int i = strlen(num) - 1; i >= 0; i--) {
    int temp = num[i] - '0';
    count[temp]++;
    temp = temp * 2 + flag;
    flag = 0;
    if(temp >= 10) {
      temp = temp - 10;
      flag = 1;
    }
    num[i] = (temp + '0');
    count[temp]--;
  }
  for(int i = 0; i < 10; i++)
    if(count[i] != 0)
      flag1 = 1;
  if(flag1 == 1 || flag == 1)
    printf("No\n");
  else
    printf("Yes\n");
  if(flag == 1)
    printf("1");
  for(int i = 0; i < strlen(num); i++)
    printf("%c", num[i]);
  return 0;
}
