#include <iostream>

using std::cin, std::cout, std::endl;

int main() {
  int i;
  while (cin >> i) {
    if (i == 42) {
      break;
    }
  }

  return 0;
}
