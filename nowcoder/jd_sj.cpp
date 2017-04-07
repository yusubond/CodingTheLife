#include <iostream>
#include <math.h>
using namespace std;
void area() {
  double a, b, c;
  cout << "Input a b c:";
  cin >> a >> b >> c;
  if(a+b>c&&a+c>b&&c+b>a) {
    double l=(a+b+c)/2;
    double s=sqrt(l*(l-a)*(l-b)*(l-c));
    cout << "The area is:" << s << endl;
  }
  else {
    cout << "Error" << endl;
  }
}
int main() {
  area();
  return 0;
}
