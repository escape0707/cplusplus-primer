#include <iostream>

using std::cin, std::cout, std::endl;

int main() {
  int i, j, k;
  cin >> i >> j >> k;
  cout << (i != j < k) << ' ' << (i != (j < k)) << endl;

  return 0;
}
