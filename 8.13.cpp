#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>
#include "PersonInfo.h"

using std::cin, std::cout, std::cerr, std::endl;
using std::copy;
using std::getline;
using std::ifstream, std::ofstream;
using std::istream_iterator, std::back_inserter;
using std::istringstream, std::ostringstream;
using std::string;
using std::vector;

int main() {
  string line;
  vector<PersonInfo> people;

  ifstream fin("a.in");
  while (getline(fin, line)) {
    istringstream record(line);
    PersonInfo info;
    record >> info.name;
    copy(istream_iterator<PersonInfo::number_type>(record),
         istream_iterator<PersonInfo::number_type>(),
         back_inserter(info.phones));
    people.push_back(info);
  }
  for (const PersonInfo &info : people) {
    cout << info << endl;
  }

  for (const PersonInfo &entry : people) {
    ostringstream formatted, badNums;
    for (const auto &number : entry.phones) {
      if (!valid(number)) {
        badNums << ' ' << number;
      } else {
        formatted << ' ' << format(number);
      }
    }
    if (badNums.str().empty()) {
      cout << entry.name << ' ' << formatted.str() << endl;
    } else {
      cerr << "input error: " << entry.name << " invalid number(s) "
           << badNums.str() << endl;
    }
  }
}
