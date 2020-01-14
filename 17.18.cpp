#include <iostream>
using std::cout;
using std::endl;

#include <regex>
using std::regex;
using std::sregex_iterator;

#include <string>
using std::string;

int main() {
  string file = "albeit neighbour neighbor receipt freind theif receive";
  string pattern =
      "\\b(?!(albeit|neighbou?r)\\b)[[:alpha:]]*([^c]ei|cie)[[:alpha:]]*";
  regex r(pattern, regex::icase);
  for (sregex_iterator it(file.cbegin(), file.cend(), r), end_it; it != end_it;
       ++it) {
    cout << it->str() << endl;
  }
}
