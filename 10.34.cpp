#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using std::copy;
using std::cout, std::endl;
using std::ostream_iterator;
using std::vector;

int main() {
  vector<int> ivec = {0, 1, 2, 3, 4};

  copy(ivec.crbegin(), ivec.crend(), ostream_iterator<int>(cout, " "));
  cout << endl;
}