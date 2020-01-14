#include <iostream>
#include <regex>
#include <string>

using std::cin, std::cout, std::endl;
using std::regex, std::regex_match;
using std::string;

int main() {
  regex r("[[:alpha:]*([^^c]ei|cie)[[:alpha:]]*");
  for (string word; cin >> word;) {
    if (regex_match(word, r)) {
      cout << "Typo!" << endl;
    } else {
      cout << "Okay." << endl;
    }
  }
}
