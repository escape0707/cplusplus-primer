#include <iostream>
#include <iterator>
#include <regex>
#include <sstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::istream_iterator;
using std::ostringstream;
using std::regex;
using std::sregex_iterator;
using std::string;

int main() {
  regex r("\\d{5}-?\\d{4}");
  string input =
      dynamic_cast<ostringstream &>(ostringstream() << cin.rdbuf()).str();
  .for (sregex_iterator it(istream_iterator<string>(cin),
                           istream_iterator<string>(), r),
        end_it;
        it != end_it; ++it) {}
}
