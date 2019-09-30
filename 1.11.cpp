#include <iostream>

int main() {
  int v1 = 0, v2 = 0;
  std::cout << "Enter two numbers:" << std::endl;
  std::cin >> v1 >> v2;
  int step = v1 < v2 ? 1 : -1;
  while (v1 != v2) {
    std::cout << v1 << ' ';
    v1 += step;
  }
  std::cout << v2 << std::endl;
}