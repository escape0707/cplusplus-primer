#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>

using std::copy, std::find;
using std::cout, std::endl;
using std::list;
using std::ostream_iterator;

int main() {
  list<int> ilst = {-3, -2, -1, 0, 1, 2, 0, 4, 5};

  *find(ilst.rbegin(), ilst.rend(), 0) = 42;

  copy(ilst.cbegin(), ilst.cend(), ostream_iterator<int>(cout, " "));
  cout << endl;
}