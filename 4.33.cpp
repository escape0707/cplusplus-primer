#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int main() {
  bool someValue = false;
  int x = 0, y = 1;

  someValue ? ++x, ++y : --x, --y;
  cout << x << ' ' << y << endl;

  x = 0, y = 1;
  (someValue ? (++x), (++y) : (--x)), (--y);
  cout << x << ' ' << y << endl;


}
