#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using std::cin, std::cout, std::endl;
using std::copy;
using std::istream_iterator, std::ostream_iterator;
using std::vector;

int main() {
  vector<int> ivec((istream_iterator<int>(cin)), istream_iterator<int>());

  copy(ivec.cbegin(), ivec.cend(), ostream_iterator<int>(cout, " "));
  cout << endl;
}