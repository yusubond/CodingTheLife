/*
* Author: subond
* Time: 2017-03-16
* Problem: 超时
* Question: 小易来到了一条石板路前，每块石板上从1挨着编号为：1、2、3.......
这条石板路要根据特殊的规则才能前进：对于小易当前所在的编号为K的 石板，小易单次只能往前跳K的一个约数(不含1和K)步，即跳到K+X(X为K的一个非1和本身的约数)的位置。 小易当前处在编号为N的石板，他想跳到编号恰好为M的石板去，小易想知道最少需要跳跃几次可以到达。
例如：
N = 4，M = 24：
4->6->8->12->18->24
于是小易最少需要跳跃5次，就可以从4号石板跳到24号石板
 */
#include <cstdio>
#include <cmath>
using namespace std;
int n, m;
int main() {
  scanf("%d %d", &n, &m);
  int count = 0, flag = 0;
  while(n != m) {
    for(int i = n - 1; i > 1 && flag == 0; i--) {
      if(n % i == 0 && n + i <= m && flag == 0) {
        n += i;
        count++;
        if(n == m)
          flag = 1;
        else
          flag = 0;
        break;
      }
    }
  }
  printf("%d", count);
  return 0;
}
