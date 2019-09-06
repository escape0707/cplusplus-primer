#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::domain_error, std::invalid_argument;
using std::string;
using std::vector;

int main() {
  int v1, v2;
  cin >> v1 >> v2;
  if (v2 == 0) {
    throw domain_error("Division by 0");
  }
  cout << v1 / v2 << endl;

  return 0;
}
