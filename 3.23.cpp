#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int main() {
  vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  for (auto it = ivec.begin(); it != ivec.end(); ++it) {
    *it *= 2;
  }
  for (const auto &i : ivec) {
    cout << i << ' ';
  }
  cout << endl;
}
