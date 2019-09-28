#include <iostream>
#include <list>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::list;
using std::string;
using std::vector;

template <typename T, typename U>
bool test(const T &a, const U &b) {
  if (a.size() != b.size()) {
    return false;
  }

  auto beg1 = a.cbegin(), beg2 = b.cbegin();
  auto end1 = a.cend();

  while (beg1 != end1 && *beg1 == *beg2) {
    ++beg1;
    ++beg2;
  }

  return beg1 == end1;
}

int main() {
  vector<int> v1 = {0, 1, 1, 2};
  list<int> v2 = {0, 1, 1, 2, 3, 5, 8};

  cout << std::boolalpha << test(v1, v2) << endl;

  return 0;
}
