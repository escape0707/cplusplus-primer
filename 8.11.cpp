#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>
#include "PersonInfo.h"

using std::cin, std::cout, std::endl;
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

  istringstream record;
  while (getline(cin, line)) {
    record.clear();
    record.str(line);
    PersonInfo info;
    record >> info.name;
    copy(istream_iterator<string>(record), istream_iterator<string>(),
         back_inserter(info.phones));
    people.push_back(info);
  }
  for (const PersonInfo &info : people) {
    cout << info << endl;
  }
}
