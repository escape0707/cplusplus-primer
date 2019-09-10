#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

// calculate val!, which is 1 * 2 * 3 ... * val
int factorial(int val) {
  if (val != 0) { // can't handle val less than 0
    return factorial(val - 1) * val;
  }
  return 1;
}

int main() {
  cout << factorial(5) << endl;
}
