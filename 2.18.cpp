#include <iostream>

int main() {
  int value = 0, *point = nullptr;
  std::cout << value << ' ' << point << ' ' /* << *point */ << std::endl;
  point = &value;
  *point = 1;
  std::cout << value << ' ' << point << ' ' << *point << std::endl;
}