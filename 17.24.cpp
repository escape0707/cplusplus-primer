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
  const string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
  regex r(phone);
  string s;
  const string fmt = "$2.$5.$7";
  for (string s; getline(cin, s);) {
    cout << regex_replace(s, r, fmt) << endl;
  }
}
