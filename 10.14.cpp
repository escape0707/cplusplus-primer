#include <iostream>

using std::cout, std::endl;

int main() {
  auto lambda = [](int i, int j) { return i + j; };
  cout << lambda(40, 2) << endl;
}