#include <cstddef>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using std::begin, std::end;
using std::cin, std::cout, std::endl;
using std::size_t, std::ptrdiff_t;
using std::string;
using std::vector;

int main() {
  int arr[10];
  for (int *p = begin(arr); p != end(arr); ++p) {
    *p = 0;
  }

  for (auto i : arr) {
    cout << i << ' ';
  }
  cout << endl;
}
