#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::isupper, std::tolower;
using std::string;
using std::vector;

bool has_capital(const string &s) {
  for (const auto &c : s) {
    if (isupper(c)) {
      return true;
    }
  }
  return false;
}

void to_lower(string &s) {
  for (auto &c : s) {
    c = tolower(c);
  }
}

int main() {


}
