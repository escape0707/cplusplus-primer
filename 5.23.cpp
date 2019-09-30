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
  try {
    if (!(cin >> v1 >> v2)) {
      throw invalid_argument("Not valid input");
    }
    if (v2 == 0) {
      throw domain_error("Division by 0");
    }
    cout << v1 / v2 << endl;
  } catch (invalid_argument err) {
    std::cerr << err.what() << endl;
  } catch (domain_error err) {
    std::cerr << err.what() << endl;
  }


}