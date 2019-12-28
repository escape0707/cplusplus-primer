#include <iostream>
#include <vector>

using std::cout, std::endl;
using std::vector;

template <typename C>
void print(const C &c) {
  for (typename C::const_iterator beg = c.cbegin(), end = c.cend(); beg != end;
       ++beg) {
    cout << *beg << endl;
  }
}

int main() {
  vector<int> ivec = {1, 3, 5, 7, 9};
  print(ivec);
}
