#include <iostream>
#include <regex>
#include <string>

using std::cin, std::cout, std::endl;
using std::regex, std::regex_match;
using std::string;

int main() {
  regex r("[[:alpha:]]*([^c]ei|cie)[[:alpha:]]*");
  for (string word;
       static_cast<void>(cout << "Enter a word for testing, or q to quit: "),
       cin >> word;) {
    if (word == "q") {
      break;
    }
    if (regex_match(word, r)) {
      cout << "Typo!" << endl;
    } else {
      cout << "Okay." << endl;
    }
  }
}
