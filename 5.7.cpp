#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int get_value() {
  return 0;
}

int main() {
  int ival1, ival2, ival, minval, occurs;

  if (ival1 != ival2) {
    ival1 = ival2;
  } else {
    ival1 = ival2 = 0;
  }

  if (ival < minval) {
    minval = ival;
    occurs = 1;
  }

  cout << "ival = ";
  if (int ival = get_value()) {
    cout << ival;
  } else {
    cout << '0';
  }
  cout << endl;

  if (ival == 0) {
    ival = get_value();
  }

  return 0;
}
