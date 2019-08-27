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
  char ca1[] = "Hello", ca2[] = "world!", ca3[sizeof(ca1) + sizeof(ca2)];
  strcpy(ca3, ca1);
  strcat(ca3, ca2);
  cout << ca3 << endl;

  return 0;
}
