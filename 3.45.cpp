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
  int ia[3][4];

  for (const auto &row : ia) {
    for (const auto &element : row) {
      cout << element << ' ';
    }
    cout << endl;
  }
  cout << endl;

  for (size_t row = 0; row < 3; ++row) {
    for (size_t col = 0; col < 4; ++col) {
      cout << ia[row][col] << ' ';
    }
    cout << endl;
  }
  cout << endl;

  for (const auto *p = ia; p < ia + 3; ++p) {
    for (const auto *q = *p; q < *p + 4; ++q) {
      cout << *q << ' ';
    }
    cout << endl;
  }
  cout << endl;
}
