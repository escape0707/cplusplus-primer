#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int main() {
  int i;
  vector<int> v;  // empty vector
  while (cin >> i) {
    v.push_back(i);  // append word to text
  }

  return 0;
}
