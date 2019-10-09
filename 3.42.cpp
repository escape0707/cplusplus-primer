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
  vector<int> ivec = {0, 1, 2, 3, 4, 5};
  int arr[ivec.size()];
  int *p = arr;
  for (const auto &i : ivec) {
    *p++ = i;
  }

  for (const auto &i : arr) {
    cout << i << ' ';
  }
  cout << endl;
}
