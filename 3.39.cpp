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
  char ca1[] = "Hello", ca2[] = "world!";
  string str1 = ca1, str2 = ca2;

  cout << str1.compare(str2) << endl;
  cout << strcmp(ca1, ca2) << endl;

  return 0;
}
