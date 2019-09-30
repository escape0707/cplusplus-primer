#include <cstddef>
#include <cstring>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using std::begin, std::end, std::cbegin, std::cend;
using std::cin, std::cout, std::endl;
using std::size_t, std::ptrdiff_t;
using std::string;
using std::strlen, std::strcmp, std::strcat, std::strcpy;
using std::vector;

int main() {
  const char ca[] = {'h', 'e', 'l', 'l', 'o'}; // disaster: not null-terminated
  const char *cp = ca;
  while (*cp) {
    cout << *cp << endl;
    ++cp;
  }


}
