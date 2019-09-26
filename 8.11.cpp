#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "PersonInfo.h"

using std::cin, std::cout, std::endl;
using std::getline;
using std::ifstream, std::ofstream;
using std::istringstream, std::ostringstream;
using std::string;
using std::vector;

int main() {
  string line, word;
  vector<PersonInfo> people;

  istringstream record;
  while (getline(cin, line)) {
    record.clear();
    record.str(line);
    PersonInfo info;
    record >> info.name;
    while (record >> word) {
      info.phones.push_back(word);
    }
    people.push_back(info);
  }
  for (const PersonInfo &info : people) {
    cout << info << endl;
  }
}
