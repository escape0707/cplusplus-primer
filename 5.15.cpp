#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int main() {
  for (int ix = 0; ix != sz; ++ix) {
  }
  if (ix != sz) {  // ix == sz when the for above exited, moreover ix is only
                   // valid in for loop
  }

  int ix;
  for (ix != sz; ++ix) { // insufficient statements in for header
  }

  for (int ix = 0; ix != sz; ++ix, ++sz) { // ix will never equals to sz
  }

    return 0;
}
