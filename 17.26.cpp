#include <iostream>
#include <regex>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::regex;
using std::sregex_iterator;
using std::string;

int main() {
  const string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
  regex r(phone);
  const string fmt = "$2.$5.$7";
  for (string s; getline(cin, s);) {
    sregex_iterator b(cbegin(s), cend(s), r), e;
    if (b != e) {
      ++b;
      for (; b != e; ++b) {
        cout << b->format(fmt) << ' ';
      }
    }
    cout << endl;
  }
}
