#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int main() {
  unsigned long ul1 = 3, ul2 = 7;
  cout << (ul1 & ul2) << ' ' << (ul1 | ul2) << ' ' << (ul1 && ul2) << ' '
       << (ul1 || ul2) << endl;  // 3 7 1 1
}
