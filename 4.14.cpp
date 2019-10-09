#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int i;

int main() {
  // if (42 = i) { // error
    // ;
  // }

  if (i = 42) { // 42 is always converted to true
    ;
  }
}
