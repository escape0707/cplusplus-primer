#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include "HasPtr.h"

using std::cbegin, std::cend, std::ostream_iterator;
using std::copy, std::sort;
using std::cout, std::endl;
using std::string;
using std::vector;

int main() {
  // note that sort() may use iter_swap() and iter_swap() maybe don't use swap()
  // especially when using the following line.
  // const string sarr[] = {"a", "c", "b", "d", "a"};
  const string sarr[] = {"a", "c", "b", "d", "a", "a", "c", "b", "d", "a",
                         "a", "c", "b", "d", "a", "a", "c", "b", "d", "a"};
  vector<HasPtr> vh(cbegin(sarr), cend(sarr));
  swap(vh[0], vh[1]);
  copy(vh.cbegin(), vh.cend(), ostream_iterator<HasPtr>(cout, " "));
  cout << endl;

  sort(vh.begin(), vh.end());
  copy(vh.cbegin(), vh.cend(), ostream_iterator<HasPtr>(cout, " "));
  cout << endl;
}
