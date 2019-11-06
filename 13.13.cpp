#include <iostream>
#include <string>

#include "X.h"

using std::cout, std::endl;
using std::string;

X val(X x) {
  cout << "Into X val(X x)." << endl;
  return x;
}

X &ref(X &x) {
  cout << "Into X& ref(X& x). " << endl;
  return x;
}

int main() {
  X x("x");
  X a(x), b = a;
  // X omit = "omit";
  X omit = string("omit");
  omit = x;
  cout << endl;

  X test("test");
  cout << "Pass:" << endl;
  cout << "Statement: X retv = val(test);" << endl;
  X retv = val(test);
  cout << "Statement: X retr = ref(test);" << endl;
  X retr = ref(test);
  // X &rretv = val(x);
  cout << "Statement: X &rretr = ref(test);" << endl;
  X &rretr = ref(test);

  X *px = new X("pointed");
}
