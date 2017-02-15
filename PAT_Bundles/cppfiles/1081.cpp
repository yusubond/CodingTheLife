#include <cstdio>
#include <cstdlib>
using namespace std;
long long gcd(long long a, long long b) {
  return b == 0 ? abs(a) : gcd(b, a % b);
}
int main() {
  int n;
  long long a, b, suma = 0, sumb = 1, gcdvalue;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%lld/%lld", &a, &b);
    gcdvalue = gcd(a, b);  //求其最大公约数
    //约分
    a = a / gcdvalue;
    b = b / gcdvalue;
    //分式计算
    suma = a * sumb + b * suma;
    sumb = b * sumb;
    gcdvalue = gcd(suma, sumb);
    //约分
    suma = suma / gcdvalue;
    sumb = sumb / gcdvalue;
  }
  long long x = suma / sumb;
  long long y = suma - (sumb * x);
  if(x != 0) {
    printf("%lld", x);
    if(y != 0) {
      printf(" %lld/%lld", y, sumb);
    }
  } else {
    if(y != 0) {
      printf("%lld/%lld", y, sumb);
    } else {
      printf("0");
    }
  }
  return 0;
}
