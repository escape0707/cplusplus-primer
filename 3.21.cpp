#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int main() {
  vector<string> text{"Hello, ", "world!", "", "Hi, ", "you!"};
  // print each line in text until the first blank line
  for (vector<string>::const_iterator it = text.cbegin();
       it != text.cend() && !it->empty(); ++it) {
    cout << *it << endl;
  }

  for (const string &str : text) {
    if (str.empty()) {
      break;
    }
    cout << str << endl;
  }
}
