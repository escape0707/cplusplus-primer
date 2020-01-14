#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <regex>
using std::regex;
using std::sregex_iterator;

int main() {
  string file = "albeit neighbor reciept receipt freind theif receive";
  string pattern = "([^c]ei|cie)";
  pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
  pattern = "\\b(?!(albeit|neighbor)\\b)" + pattern;
  regex r(pattern, regex::icase);
  for (sregex_iterator it(file.cbegin(), file.cend(), r), end_it; it != end_it;
       ++it) {
    cout << it->str() << endl;
  }
}
