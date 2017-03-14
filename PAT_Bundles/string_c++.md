## 字符串处理函数

### 1. 头文件string.h `#include<string.h>`

strcmp(): 字符串比较函数，比较两个字符串的大小，一般的形式为i = strcmp(str1, str2)。**str1和str2为char数组形式**。

str1小于str2时，返回值为负值；str1等于str2时，返回值为零；str1大于str2时，返回正值。

strcpy()字符串拷贝函数，用于拷贝两个字符串。char数组形式。

strcpy(str1, str2)

另外，getline()也在string.h头文件中。

### 2. 头文件cstring`#include<cstring>`

成员函数length():可求字符串长度

```c++
string s;
for(int i = 0; i < s.length(); i++) {
  cout << s[i];
}
```

### 3. 头文件cctype`#include<cctype>``

cctype头文件中的函数

isalnum(c): 当c为字母或数字时为真  
isalpha(c): 当c为字母时为真  
isdigit(c): 当c为数字时为真  
islower(c): 当c为小写字母时为真  
isupper(c): 当c为大小字母时为真  
tolower(c): 当c是大写字母时，输出对应的小写字母，否则原样输出  
toupper(c): 当c是小写字母时，输出对应的大写字母，否则原样输出  
