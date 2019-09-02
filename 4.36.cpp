#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int main() {
  int i = 2;
  double d = 1.9;

  i *= d;
  cout << i << endl;

  i = 2;
  i *= static_cast<int>(d);
  cout << i << endl;
}
