#include <iostream>

#include "StrBlobPtr.h"

using std::cout, std::endl;

class P {
 public:
  StrBlobPtr *p;
  StrBlobPtr *operator->() { return p; }
};

int main() {
  StrBlob b = {"Hello, ", "world!"};
  StrBlobPtr p(b);
  P pp{&p};
  cout << pp->operator*() << endl;
}
