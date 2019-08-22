#include <iostream>

int main() {
  int i = 0, &ri = i;
  auto j = ri;
  decltype(ri) k = i;
  j = 1;
  k = 2;
  std::cout << i << std::endl;
}