#include <iostream>
#include <list>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::list;
using std::string;
using std::vector;

template <typename C1, typename C2>
bool test(const C1 &a, const C2 &b) {
  if (a.size() != b.size()) {
    return false;
  }

  typename C1::const_iterator beg1 = a.cbegin();
  const typename C1::const_iterator &end1 = a.cend();
  typename C2::const_iterator beg2 = b.cbegin();

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
}
