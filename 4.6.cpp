#include <iostream>

using std::cout, std::endl;

int main() {
  int i = 1;
  cout << (i % 2 ? "odd" : "even") << endl;
  i = 2;
  cout << (i % 2 ? "odd" : "even") << endl;
}