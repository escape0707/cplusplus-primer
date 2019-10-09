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

template <typename T, typename U>
int compare(const T &a, const U &b) {
  auto beg1 = std::cbegin(a), beg2 = std::cbegin(b);
  const auto &end1 = std::cend(a), &end2 = std::cend(b);

  while (beg1 != end1 && beg2 != end2) {
    if (*beg1 != *beg2) {
      return *beg1 - *beg2;
    }
    ++beg1;
    ++beg2;
  }
  return (beg1 != end1) - (beg2 != end2);
}

int main() {
  int a[] = {1, 2, 3, 4, 5}, b[] = {1, 2, 3, 4, 5, 6};
  vector<int> va = {1, 2, 3, 4, 5}, vb = {1, 2, 3, 4, 5, 6};

  cout << compare(a, b) << ' ' << compare(vb, va) << ' ' << compare(a, va)
       << ' ' << compare(b, va) << endl;
}
