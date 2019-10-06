#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::fill_n;
using std::ostream_iterator;
using std::string;
using std::vector;

int main() {
  vector<int> ivec(10, 42);
  copy(ivec.cbegin(), ivec.cend(), ostream_iterator<int>(cout, " "));
  cout << endl;
  fill_n(ivec.begin(), 5, 0);
  copy(ivec.cbegin(), ivec.cend(), ostream_iterator<int>(cout, " "));
  cout << endl;
}
