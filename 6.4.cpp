#include <iostream>
#include <string>
#include <vector>
#include "Chapter6.h"

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int fact(unsigned val) {
  unsigned ret = 1;
  while (val) {
    ret *= val--;
  }
  return ret;
}

int main() {
  cout << "Enter a number: ";
  unsigned j;
  // warning: cin will implicity convert negative int read into unsigned
  while (cin >> j) {
    cout << "The factorial of " << j << " is " << std::flush;
    cout << fact(j) << endl;
  }
}
