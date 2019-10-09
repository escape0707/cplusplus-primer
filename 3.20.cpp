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

  for (decltype(ivec.size()) ix = 1; ix < ivec.size(); ix += 2) {
    cout << ivec[ix - 1] + ivec[ix] << ' ';
  }
  cout << endl;

  for (decltype(ivec.size()) i = 0, j = ivec.size() - 1; i <= j; ++i, --j) {
    cout << ivec[i] + ivec[j] << ' ';
  }
  cout << endl;
}
