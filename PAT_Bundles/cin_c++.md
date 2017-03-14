## C++中cin, cin.get(), cin.getline(), getline(), gets()等用法

### 1. cin >>

用法1：这是最基本，最常用的用法。例如，int a; cin >> a;

**注意**：**>>可以过滤掉不可见字符**。如 空格，回车，TAB等。

用法1：接受一个字符串，**遇 空格，回车，TAB 都结束**。例如：

```c++
#include <iostream>
using namespace std;
int main() {
  char a[20];
  cin >> a;
  cout << a << endl;
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

### 4. getline():接收一个字符串，可以接收空格并输出，需使用头文件 #include<string.h>

```c++
#include <iostream>
#include <string.h>
using namespace std;
int main() {
  string s1;
  getline(cin, s1);
  cout << s1 << endl;
}
```

**注意**：cin.getline()属于istream流，而getline()属于string流，这两个是不一样的函数。
