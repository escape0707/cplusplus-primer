#include <initializer_list>
#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::initializer_list;
using std::string;
using std::vector;

int sum(initializer_list<int> il) {
  int ret = 0;
  for (const int &elem : il) {
    ret += elem;
  }
  return ret;
}

int main() {
  cout << sum({0, 1, 2, 3, 4, 5, 6, 7, 8, 9}) << endl;
}
