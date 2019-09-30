#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int main() {
  int x[10];
  int *p = x;
  cout << sizeof(x) / sizeof(*x) << endl;  // 10
  cout << sizeof(p) / sizeof(*p) << endl;  // 2 if 64-bit system, 1 if 32-bit
  cout << sizeof(p) << " / " << sizeof(*p) << endl;


}
