#include <iostream>
#include <string>

using std::cin, std::cout, std::endl;
using std::string;

int main() {
  const string s = "Keep out!";
  for (auto &c : s) {
    // c is const char&
  }

  return 0;
}
