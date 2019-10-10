#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

template <typename C1, typename C2>
bool test(const C1 &a, const C2 &b) {
  auto beg1 = std::cbegin(a);
  const auto &end1 = std::cend(a);
  auto beg2 = std::cbegin(b);
  const auto &end2 = std::cend(b);

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
}
