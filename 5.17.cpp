#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

template <typename T, typename U>
bool test(const T &a, const U &b) {
  auto beg1 = a.cbegin(), beg2 = b.cbegin();
  auto end1 = a.cend(), end2 = b.cend();

  while (beg1 != end1 && beg2 != end2 && *beg1 == *beg2) {
    ++beg1;
    ++beg2;
  }

  return beg1 == end1 || beg2 == end2;
}

int main() {
  vector<int> v1 = {0, 1, 1, 2};
  vector<int> v2 = {0, 1, 1, 2, 3, 5, 8};

  cout << test(v1, v2) << endl;

  return 0;
}
