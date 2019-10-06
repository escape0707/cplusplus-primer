#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using std::accumulate;
using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int main() {
  vector<int> ivec{0, 1, 2, 3, 4, 5};
  cout << accumulate(ivec.cbegin(), ivec.cend(), 0) << endl;
}
