#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using std::all_of;
using std::bind;
using std::cout, std::endl;
using std::modulus;
using std::vector;
using std::placeholders::_1;

int main() {
  vector<int> vi = {2, 3};
  int value = 9;
  cout << std::boolalpha
       << !all_of(vi.cbegin(), vi.cend(), bind(modulus(), value, _1)) << endl;
}
