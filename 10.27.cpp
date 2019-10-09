#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
#include <iterator>

using std::back_inserter;
using std::copy, std::unique_copy;
using std::cout, std::endl;
using std::list;
using std::ostream_iterator;
using std::vector;

int main() {
  vector<int> ivec = {0, 1, 1, 2, 3, 5, 8};
  list<int> ilst;

  unique_copy(ivec.cbegin(), ivec.cend(), back_inserter(ilst));
  copy(ilst.cbegin(), ilst.cend(), ostream_iterator<int>(cout, " "));
  cout << endl;
}