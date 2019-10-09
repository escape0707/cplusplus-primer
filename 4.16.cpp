#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int *p;
int i;

int *getPtr() {
  return nullptr;
}

int main() {
  // if (p = getPtr() != 0) {
  //   ;
  // }

  // if (i = 1024) {
  //   ;
  // }

  if ((p = getPtr()) != 0) {
    ;
  }

  if (i == 1024) {
    ;
  }
}
