#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int main() {
  vector<string> text{"Hello, ", "world!", "", "Hi, ", "you!"};
  // print each line in text up to the first blank line
  for (auto it = text.begin(); it != text.end() && !it->empty(); ++it) {
    for (auto &c : *it) {
      c = toupper(c);
    }
  }

  for (const auto &str : text) {
    cout << str << endl;
  }
}
