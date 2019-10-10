#include <iostream>
#include <list>
#include <vector>

using std::cout, std::endl;
using std::list;
using std::ostream;
using std::vector;

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  if (!vec.empty()) {
    typename vector<T>::const_iterator begin = vec.cbegin();
    const typename vector<T>::const_iterator &end = vec.cend();
    os << *begin++;
    while (begin != end) {
      os << ' ' << *begin++;
    }
  }
  return os;
}

int main() {
  list<int> ilist = {0, 1, 2, 3, 4};
  vector<int> ivec = {5, 6, 7, 8, 9};

  vector<double> dvec1(ilist.cbegin(), ilist.cend());
  vector<double> dvec2(ivec.cbegin(), ivec.cend());

  cout << dvec1 << '\n' << dvec2 << endl;
}