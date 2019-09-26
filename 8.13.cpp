#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "PersonInfo.h"

using std::cin, std::cout, std::cerr, std::endl;
using std::getline;
using std::ifstream, std::ofstream;
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
    PersonInfo::number_type word;
    while (record >> word) {
      info.phones.push_back(word);
    }
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
