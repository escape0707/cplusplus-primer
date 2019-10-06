#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using std::cin, std::cout, std::endl;
using std::copy, std::count;
using std::istream_iterator;
using std::vector;

int main() {
  // cout << count(istream_iterator<int>(cin), istream_iterator<int>(), 42) <<
  // endl;

  vector<int> ivec;
  copy(istream_iterator<int>(cin), istream_iterator<int>(),
       back_inserter(ivec));

  cout << count(ivec.cbegin(), ivec.cend(), 42) << endl;
}