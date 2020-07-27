#include <iostream>
#include <regex>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::regex;
using std::regex_search;
using std::smatch;
using std::string;

int main() {
  const string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
  regex r(phone);
  smatch m;
  const string fmt = "$2.$5.$7";
  for (string s; getline(cin, s);) {
    if (regex_search(s, m, r)) {
      cout << m.format(fmt) << endl;
    }
  }
}
