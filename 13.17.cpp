// see also numbered.h

#include <iostream>

#include "numbered.h"

using std::cout, std::endl;

void f(const numbered &s) {
  cout << s.mysn << endl;
}

// void f(numbered s) {
//   cout << s.mysn << endl;
// }

int main() {
  numbered a, b = a, c = b;
  f(a);
  f(b);
  f(c);
}
