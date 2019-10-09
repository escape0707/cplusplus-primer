#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int main() {
  char cval;
  int ival;
  unsigned int ui;
  float fval;
  double dval;

  cval = 'a' + 3;  // 'a' promoted to int, then the sum is converted to char;
  fval =
      ui - ival * 1.0;  // ival is converted to double, the product is conveted
                        // to unsigned int, the difference is converted to float
  dval =
      ui * fval;  // ui is converted to float, the product is promoted to double
  cval = ival + fval +
         dval;  // ival is converted to float, then the sum is promoted to
                // double, then they finally turned into a char;
}
