## 输入输出流

C++中常见的输入流包括cin, cin.get(), cin.getline(), getline(), gets()，以下是它们的基本用法：

### 1. cin >>

用法1：这是最基本，最常用的用法。例如，int a; cin >> a;

**注意**：**>>可以过滤掉不可见字符**。如 空格，回车，TAB等。

用法1：接受一个字符串，**遇 空格，回车，TAB 都结束**。例如：

```c++
#include <iostream>
using namespace std;
int main() {
  string word;
  while(cin >> word) {
    cout << a << endl;
  }
  return 0;
}
```

### 2. cin.get()

用法1：cin.get(字符变量名)可以用来接收字符。例如：

```c++
#include <iostream>
using namespace std;
int main() {
  char c;
  c = cin.get();   //or cin.get(c);
  cout << c <<endl;
  return 0;
}
```

用法2：cin.get(字符数组名，接收字符数目)。例如：

```c++
#include <iostream>
using namespace std;
int main() {
  char a[20];
  cin.get(a, 20);   //只接收20个字符(实际上为19个字符 + 1个'\0')
  cout << a << endl;
  return 0;
}
```

### 3. cin.getline():接收一个字符串，可以接收空格并输出

```c++
#include <iostream>
using namespace std;
int main() {
  char m[20];
  cin.getline(m, 5);  //接收5个字符到m中，实际为4个 + 1个'\0'
  cout << m << endl;
  return 0;
}
```

**注意**：cin.getline()实际上有三个参数，cin.getline(接收字符数组名，接收个数，结束字符)。默认结束字符为'\0'。

例如，cin.getline(m, 10, 'a');  //当遇到'a'时，结束接收，即只接收'a'之前的字符

### 4. getline():是一个函数，可以接收一个字符串，也可以接收空格并输出。

**注意**：c++中有两个getline()函数，一个是在string头文件中，定义的是一个全局的函数，函数声明是
```
istream& getline (istream& is, string& str, char delim )
与
istream& getline ( istream& is, string& str )
```

另一个则是istream的成员函数，函数声明是

```
istream& getline (char* s, streamsize n )
与
istream& getline (char*s, streamsize n, char delim )
```

第二个getline是将读取的字符串存储在char数组中而不可以将该参数声明为string类型，因为C++编译器无法执行此默认转换。

头文件string中的getline()函数从给定的输入流中读取内容，直到遇到换行符为止(注意换行符也被读进来了)，然后将所读内容存入string对象中(注意不存换行符)。

```c++
#include <iostream>
#include <string>
using namespace std;
int main() {
  string line;
  while(getline(cin, line))
    cout << s1 << endl;
}
```
