#include <iostream>
#include <string>
#include <iterator>
#include <vector>

using std::cin, std::cout, std::endl;
using std::istream_iterator;
using std::string;
using std::vector;

int main() {
  vector<int> ivec((istream_iterator<int>(cin)), istream_iterator<int>());

  for (auto beg = ivec.cbegin(); beg != ivec.cend() && beg + 1 != ivec.cend(); beg += 2) {
    cout << *beg + *(beg + 1) << ' ';
  }
  cout << endl;

  for (auto beg = ivec.cbegin(), end = ivec.cend() - 1; beg <= end; ++beg, --end) {
    cout << *beg + *end << ' ';
  }
  cout << endl;
}
