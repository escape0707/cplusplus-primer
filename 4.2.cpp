#include <iostream>
#include <vector>

using std::cin, std::cout, std::endl;
using std::vector;

int main() {
  vector<int> vec = {0, 1, 2};
  cout << *((vec.begin)()) << ' ' << *vec.begin() << endl;
  cout << (*((vec.begin)())) + 1 << ' ' << *vec.begin() + 1 << endl;
}