#include <forward_list>
#include <iostream>
#include <list>

using std::cout, std::endl;
using std::forward_list;
using std::list;
using std::ostream;

template <typename T>
ostream &operator<<(ostream &os, const forward_list<T> &c) {
  for (const auto &elem : c) {
    os << elem << ' ';
  }
  return os;
}

template <typename T>
ostream &operator<<(ostream &os, const list<T> &c) {
  for (const auto &elem : c) {
    os << elem << ' ';
  }
  return os;
}

int main() {
  list<int> ilist{0, 1, 2, 3, 4, 5};
  for (auto iter = ilist.cbegin(); iter != ilist.cend();) {
    if (*iter & 1) {
      ilist.insert(iter, *iter);  // list::insert won't invalidate any iterator
      ++iter;
    } else {
      iter = ilist.erase(iter);
    }
  }
  cout << ilist << endl;

  forward_list<int> iflist{1, 2, 3, 4, 5, 6, 7};
  for (auto prev = iflist.cbefore_begin(), curr = iflist.cbegin();
       curr != iflist.cend();) {
    if (*curr & 1) {
      prev = curr = iflist.insert_after(curr, *curr);
      ++curr;
    } else {
      curr = iflist.erase_after(prev);
    }
  }
  cout << iflist << endl;
}