#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

using std::copy;
using std::cout, std::endl;
using std::list;
using std::ostream_iterator;
using std::vector;

int main() {
  vector<int> ivec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  list<int> ilst(ivec.crend() - 8, ivec.crend() - 3);
  copy(ilst.cbegin(), ilst.cend(), ostream_iterator<int>(cout, " "));
  cout << endl;
}