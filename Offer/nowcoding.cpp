#include <iostream>
using namespace std;
/*
功能：数值的整数次方，不要考虑大数情况
 */
bool Equal(double num1, double num2) {
  if((num1 - num2) > -0.0001 && (num1 - num2) < 0.0001)
    return true;
  else
    return false;
}
double PowerUn(double base, unsigned int exponent) {
  if(exponent == 0)
    return 1.0;
  if(exponent == 1)
    return base;
  double result = PowerUn(base, (exponent >> 1));
  result *= result;
  if((exponent & 0x1) == 1)
    result *= base;
  return result;
}
double Power(double base, int exponent) {
  if(Equal(base, 0.0) && exponent < 0)
    return 0.0;
  unsigned int absexponent = (unsigned int) exponent;
  double result = PowerUn(base, absexponent);
  if(base < 0.0)
    result = 1.0 / result;
  return result;
}
int main() {
  cout << Power(2.5, 3) << endl;
  return 0;
}
