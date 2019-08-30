#include <iostream>

using std::cin, std::cout, std::endl;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a < b && b < c && c < d) {
    cout << "OK" << endl;
  }

  return 0;
}
