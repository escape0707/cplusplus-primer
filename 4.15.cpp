#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

double dval;
int ival;
int *pi;

int main() {
  // dval = ival = pi = 0; // error: invalid conversion from int* to int
  // pi = ival = dval = 0; // even this is an error, ival may not be 0 in runtime
  dval = ival = 0;
  pi = nullptr;

  return 0;
}
