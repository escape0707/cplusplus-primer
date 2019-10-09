#include <iostream>
#include <vector>

using std::cout, std::endl;
using std::vector;

int main() {
  vector<int> ivec = {0, 1, 2, 3, 4};

  for (vector<int>::const_iterator end = ivec.cend(), begin = ivec.cbegin();
       end != begin;) {
    cout << *--end << ' ';
  }
  cout << endl;
}
