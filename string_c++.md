## 字符串处理函数

### 1. 头文件string.h `#include<string.h>`

strcmp(): 字符串比较函数，比较两个字符串的大小，一般的形式为i = strcmp(str1, str2)。**str1和str2为char数组形式**。

str1小于str2时，返回值为负值；str1等于str2时，返回值为零；str1大于str2时，返回正值。

strcpy()字符串拷贝函数，用于拷贝两个字符串。char数组形式。

strcpy(str1, str2)

### 2. 头文件cstring`#include<cstring>`

string s;
for(int i = 0; i < s.length(); i++) {
  cout << s[i];
}
