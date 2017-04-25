#include <iostream>
using namespace std;

/*
1.2题：反转字符串
输入：字符串数组指针
说明：当数组作为参数传入函数时，其实际上是传入的指针
*/
void reverse(char* str) {
  char *end = str;
  char temp;
  if(str) {
    while(*end) {
      end++;
    }
    end--;
    while(str < end) {
      temp = *str;
      *str++ = *end;
      *end-- = temp;
    }
  }
}
/*
1.3题：确定一个字符串重新排序后能否变成另外一个字符串
输入：两个字符串数组指针
输出：false 或 true
 */
bool isstr2(char *str1, char *str2) {
  int char_num[256] = {0};
  if(str1) {
    while(*str1) {
      char_num[int(*str1)]++;
      str1++;
    }
  }
  if(str2) {
    while(*str2) {
      char_num[int(*str2)]--;
      str2++;
    }
  }
  for(int i = 0; i < 255; i++) {
    if(char_num[i] != 0)
      return false;
  }
  return true;
}
/*
1.4题：将字符串中的空格替换为%20
输入：字符串数组和字符串长度，输出：无
 */
void replace(char *str, int len) {
  int newlen = 0, num = 0, i;
  for(i = 0; i < len; i++) {
    if(str[i] == ' ')
      num++;
  }
  newlen = len + num * 2;
  str[newlen] = '\0';
  for(i = len - 1; i >= 0; i--) {
    if(str[i] == ' ') {
      str[newlen - 1] = '0';
      str[newlen - 2] = '2';
      str[newlen - 3] = '%';
      newlen = newlen - 3;
    } else {
      str[newlen - 1] = str[i];
      newlen = newlen - 1;
    }
}
int main() {
  char mystr[] = "Hello World!";
  char str1[] = "abcdef g!@#$";
  char str2[] = "!@#$ab cdefg";
  char *str = mystr;
  char *p1 = str1;
  char *p2 = str2;
  //reverse(str);
  cout << str << endl;
  if(isstr2(str, p1))
    cout << "true" << endl;
  else
    cout << "false" << endl;
  if(isstr2(p1, p2))
    cout << "true" << endl;
  else
    cout << "false" << endl;
  cout << str << endl;
  replace(str, 12);
  cout << str << endl;
  return 0;
}
