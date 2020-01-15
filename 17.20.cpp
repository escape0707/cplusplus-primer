#include <iostream>
#include <regex>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::regex;
using std::smatch;
using std::sregex_iterator;
using std::string;

static bool valid(const smatch &match) {
  if (match[1].matched) {
    return match[2].matched && (!match[3].matched || match[3].str() == " ");
  } else {
    return !match[2].matched && match[3].str() == match[4].str();
  }
}

int main() {
  string phone = string("(\\()?") + "\\d{3}" + "(\\))?" + "([-. ])?" +
                 "\\d{3}" + "([-. ])?" + "\\d{4}";
  regex r(phone);
  for (string line; getline(cin, line);) {
    for (sregex_iterator it(line.cbegin(), line.cend(), r), end_it;
         it != end_it; ++it) {
      if (valid(*it)) {
        cout << "Valid: " << it->str() << endl;
      } else {
        cout << "Not valid: " << it->str() << endl;
      }
    }
  }
}
