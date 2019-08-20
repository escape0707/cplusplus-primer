#include <iostream>

int main() {
  int i = 42;
  int *p1 = &i;
  std::cout << *p1 << std::endl;
  *p1 = *p1 * *p1;
  std::cout << *p1 << std::endl << i << std::endl;
}