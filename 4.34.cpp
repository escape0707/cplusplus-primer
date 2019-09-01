#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int main() {
  bool flag;
  char cval;
  short sval;
  unsigned short usval;
  int ival;
  unsigned int uival;
  long lval;
  unsigned long ulval;
  float fval;
  double dval;

  if (fval) // if fval is 0, then false, otherwise true
    ;

  dval = fval + ival; // ival converted to float, then the sum is promoted to double

  dval + ival * cval; //  cval promoted to int, then the product is converted to double

  return 0;
}
