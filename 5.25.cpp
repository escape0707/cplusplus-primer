#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::domain_error, std::invalid_argument, std::exception;
using std::string;
using std::vector;

int main() {
  int v1, v2;
  while (cin >> v1 >> v2) {
    try {
      if (v2 == 0) {
        throw domain_error("Division by 0");
      }
      cout << v1 / v2 << endl;
    } catch (const domain_error &e) {
      cout << e.what() << "\nPlease try again:" << endl;
    }
  }
  throw invalid_argument("Not valid input");

  return 0;
}
