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
  int int_arr[] = {0, 1, 2, 3, 4, 5};
  // ivec has six elements; each is a copy of the corresponding element in int_arr
  vector<int> ivec(begin(int_arr), end(int_arr));
}
