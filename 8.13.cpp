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
  ifstream fin("a.in");
  vector<PersonInfo> people;
  {
    istringstream record_stream;
    for (string line; getline(fin, line);) {
      record_stream.str(line);
      record_stream.clear();
      people.emplace_back();
      PersonInfo &last_people = people.back();
      copy(istream_iterator<PersonInfo::number_type>(record_stream),
           istream_iterator<PersonInfo::number_type>(),
           back_inserter(last_people.phones));
    }
  }
  for (const PersonInfo &info : people) {
    cout << info << endl;
  }

  {
    ostringstream formatted, badNums;
    for (const PersonInfo &entry : people) {
      for (const string &number : entry.phones) {
        if (!valid(number)) {
          badNums << ' ' << number;
        } else {
          formatted << ' ' << format(number);
        }
      }
      string badNums_str = badNums.str();
      if (badNums_str.empty()) {
        cout << entry.name << ' ' << formatted.str() << endl;
      } else {
        cerr << "input error: " << entry.name << " invalid number(s) "
             << badNums_str << endl;
      }
    }
  }
}
