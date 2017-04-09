## string对象

### string操作

```
//初始化
string s1
string s2(n, 'c')     //初始化为连续n个字符c的串
string s3 = "value"   //s3是字面值"value"的副本，属于拷贝初始化
string s4("hello")    //s4是字面值"hello"的副本，属于直接初始化
//其他操作
is >> s               /从输入流is读入字符到s，返回is
os << s               //将s写入输出流os，返回os
getline(is, s)        //从is中读取一行赋给s，返回is
s.empty()             //s为空，返回ture
s.size()              //返回s中字符的个数，是一个无符号数，具体类型为string::size_type
                      //注意：当使用size()函数就不要使用int，这样可以避免混用int和unsigned可能带来的问题
s[n]                  //返回第n个字符的引用，位置从0开始
s1 + s2               //返回s1和s2连接的结果
s1 == s2 or s1 != s2  //等性判断，对大小写敏感
<, <=, >, >=          //按字典顺序进行比较，对大小写敏感
```

### C标准库String函数

`#include <cstring>`

C语言标准库提供的一组函数，可用于操作C风格字符串，它们定义在cstring头文件中，cstring是C语言头文件string.h的C++版本。C风格字符串的函数包括：

```
strlen(p)             //返回p的长度，空字符不计算在内
strcmp(p1, p2)        //字符串比较函数，比较两个字符串的大小，一般的形式为i = strcmp(str1, str2)
strcpy(p1, p2)        //字符串拷贝函数，用于拷贝两个字符串。
strcat(p1, p2)        //将p2附加到p1之后，返回p1
                      //p, p1, p2为char数组形式**。
length()              //成员函数，用于string对象。例如，s.length();
```

### 3. 头文件cctype`#include<cctype>``

cctype头文件中的函数

```
isalpha(c)        当c为字母时为真  
isdigit(c)        当c为数字时为真  
isxdigit(c)       当c为十六进制数字时为真
isalnum(c)        当c为字母或数字时为真
islower(c)        当c为小写字母时为真  
isupper(c)        当c为大小字母时为真  
isspace(c)        当c为空白时为真  
tolower(c)        当c是大写字母时，输出对应的小写字母，否则原样输出  
toupper(c)        当c是小写字母时，输出对应的大写字母，否则原样输出  
```
