#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int main() {
  vector<int> ivec;
  for (int number; cin >> number;) {
    ivec.push_back(number);
  }

  for (auto beg = ivec.cbegin(); beg != ivec.cend() && beg + 1 != ivec.cend(); beg += 2) {
    cout << *beg + *(beg + 1) << ' ';
  }
  cout << endl;

  for (auto beg = ivec.cbegin(), end = ivec.cend() - 1; beg <= end; ++beg, --end) {
    cout << *beg + *end << ' ';
  }
  cout << endl;

  return 0;
}
