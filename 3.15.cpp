#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int main() {
  string str;
  vector<string> v;  // empty vector
  while (cin >> str) {
    v.push_back(str);  // append word to text
  }

  return 0;
}
