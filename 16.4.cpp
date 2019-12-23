#include <functional>
#include <iostream>
#include <list>
#include <vector>

using std::cout, std::endl;
using std::equal_to;
using std::list;
using std::vector;

template <typename InputIt, typename T>
InputIt find(InputIt first, InputIt last, const T &value) {
  for (; first != last; ++first) {
    if (equal_to<T>()(*first, value)) {
      break;
    }
  }
  return first;
}

int main() {
  vector<int> ivec = {1, 3, 5, 7, 9};
  list<int> ilist = {0, 2, 4, 6, 8};
  vector<int>::const_iterator vec = ::find(ivec.cbegin(), ivec.cend(), 5);
  if (vec != ivec.cend()) {
    cout << "*vec: " << *vec << endl;
  }
  list<int>::const_iterator lst = ::find(ilist.cbegin(), ilist.cend(), 8);
  if (lst != ilist.cend()) {
    cout << "*lst: " << *lst << endl;
  }
}
