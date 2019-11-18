#include <iostream>
#include <string>

using std::cin, std::cout, std::cerr, std::endl, std::istream;
using std::string;

class ReadString {
 public:
  ReadString(istream &is = cin) : is(is) {}
  string operator()() const {
    string s;
    if (!(is >> s)) {
      s.clear();
    }
    return s;
  }

 private:
  istream &is;
};
