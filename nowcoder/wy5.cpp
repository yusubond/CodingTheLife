/*
* Author: subond
* Time: 2017-3-17
* 题意：数字的逆序计算及进位
*/
#include <string.h>
#include <cstring>
#include <iostream>
using namespace std;
int str2num(string s1, string s2) {
  int len1 = s1.length();
  int len2 = s2.length();
  int num = 0, flag = 0, i = 0, j = 0;
  int temp;
  while(i < len1 && j < len2) {
    temp = (s1[i] - '0') + (s2[j] - '0') + flag;
    num = num * 10 + temp % 10;
    if(temp > 9)
      flag = 1;
    else
      flag = 0;
    i++;
    j++;
  }
  while(i < len1)
    num = num * 10 + s1[i] - '0';
  while(j < len2)
    num = num * 10 + s2[j] - '0';
  return num;
}
int main() {
  string s1, s2;
  cin >> s1 >> s2;
  cout << str2num(s1, s2) << endl;
  return 0;
}
