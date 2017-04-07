#include <cstdio>
using namespace std;
class su {
  int a;
  char *p;
};
class susu {};
int main() {
  printf("%lu\n", sizeof(su));
  printf("%lu\n", sizeof(char*));
  printf("%lu\n", sizeof(int));
  printf("%lu\n", sizeof(susu));
  return 0;
}
