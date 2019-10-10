#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int main() {
  vector<int> ivec = {0, 1, 2, 3, 4, 5};

  for (int &i : ivec) {
    (i % 2) ? (i *= 2) : i;
  }
  for (const int &i : ivec) {
    cout << i << ' ';
  }
  cout << endl;
}
