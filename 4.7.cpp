#include <iostream>

using std::cin, std::cout, std::endl;

int main() {
  cout << 2147483647 + 1 << endl;
  cout << -2147483647 - 1 << ' ' << -(-2147483647 - 1) << endl;
  cout << (-2147483647 - 1) - 1 << endl;
}