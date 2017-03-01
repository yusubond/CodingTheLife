## c/c++中的文件重定向

c/c++语言中可以对标准输入输出流，进行重定向操作，使用freopen()函数。

stdin: **标准输入流**

默认从键盘输入，可以对其进行重定向，从磁盘文件读入。

stdout: **标准输出流**

默认向屏幕输出，可以对其进行重定向，向磁盘文件输出。

stderr: **标准错误输出流**

默认向屏幕输出，可以对其进行重定向，向磁盘文件输出。

c语言中，在头文件`#include <stdio.h>`;c++语言中。在头文件`#include <cstdio>`。

一个小🌰：

```c++
#include <cstdio>
using namespace std;
int main() {
  freopen("d:infile.txt", "r", stdin);
  //其他读入操作，如scanf(), cin

  freopen("d://outfile.txt", "w", stdout);
  //其他输出操作，如printf(), cout
  return 0;
}
```
