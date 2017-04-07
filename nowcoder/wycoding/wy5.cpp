/*
* Author: subond
* Time: 2017-3-17
* Problem：数字的逆序计算及进位
* Answer: passed
*/
#include <string.h>
#include <cstring>
#include <iostream>
using namespace std;
int flag2 = 0, flag3 = 0;
int num = 0, flag = 0, i = 0, j = 0;
int str2num(string s1, string s2) {
  int len1 = s1.length();
  int len2 = s2.length();

  int temp;
  while(i < len1 && j < len2) {
    temp = (s1[i] - '0') + (s2[j] - '0') + flag;
    num = num * 10 + temp % 10;
    if(temp > 9) {
      flag = 1;
      if(i == (len1 - 1) || j == (len2 - 1)) {
        if(i == (len1 - 1) && j == (len2 - 1))
          flag3 = 1;
        else
          flag3 = 0;
        flag2 = 1;
      }
      else
        flag2 = 0;
    }
    else
      flag = 0;
    i++;
    j++;
  }
  while(i < len1) {
    temp = (s1[i] - '0') + flag2;
    num = num * 10 + temp % 10;
    if(temp > 9)
      flag2 = 1;
    else
      flag = 0;
    i++;
  }
  while(j < len2) {
    temp = (s2[j] - '0') + flag2;
    num = num * 10 + temp % 10;
    if(temp > 9)
      flag2 = 1;
    else
      flag2 = 0;
    j++;
  }
  return num;
}
int main() {
  string s1, s2;
  cin >> s1 >> s2;
  cout << str2num(s1, s2);
  if(flag3 == 1)
    cout << "1";
  return 0;
}
