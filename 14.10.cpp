// (a) will be just fine. but (b) will be read as "10 24 .95"
// checks provided by the book cannot prevent this.
// but read as string and check each string's content will do.

#include <iostream>
#include <sstream>

#include "Sales_data.h"

using std::cout, std::endl;
using std::istringstream;

int main() {
  istringstream iss1("0-201-99999-9 10 24.95"), iss2("10 24.95 0-210-99999-9");

  Sales_data data1, data2;
  iss1 >> data1;
  iss2 >> data2;
  cout << data1 << endl;
  cout << data2 << endl;
}
