#include <iostream>
#include <string>
#include <vector>
#include "Chapter6.h"

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int abs(int val) {
  return (val < 0) ? -val : val;
}

int main() {
  int val;
  while (cin >> val) {
    cout << abs(val) << endl;
  }

  return 0;
}
