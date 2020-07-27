#include <iostream>
#include <regex>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::regex;
using std::regex_replace;
using std::string;

int main() {
  const string zip_code = "(\\d{5})(\\d{4})";
  regex r(zip_code);
  const string fmt = "$1-$2";
  for (string s; getline(cin, s);) {
    cout << regex_replace(s, r, fmt) << endl;
  }
}
