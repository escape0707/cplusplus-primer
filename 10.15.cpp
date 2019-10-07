#include <iostream>

using std::cout, std::endl;

int main() {
  int i = 42;
  auto lambda = [i](int j) { return i + j; };
  cout << lambda(42) << endl;
}