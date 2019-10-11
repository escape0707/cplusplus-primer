#include <exception>
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <sstream>
#include <string>
#include <utility>

using std::cout, std::endl;
using std::getline, std::string;
using std::ifstream;
using std::istream_iterator;
using std::istringstream;
using std::list;
using std::map;
using std::pair;
using std::runtime_error;

int main() {
  ifstream fin("a.in");
  if (!fin) {
    throw runtime_error("Can't open input file.");
  }

  map<string, list<int>> ln_num;
  {
    string s;
    istringstream iss;
    int ln = 1;  // Current line number.
    while (getline(fin, s)) {
      iss.str(s);
      iss.clear();
      while (iss >> s) {
        ln_num[s].push_back(ln);
      }
      ++ln;
    }
  }

  for (const pair<string, list<int>> p : ln_num) {
    cout << p.first << " appears on line: ";
    for (const int &ln : p.second) {
      cout << ln << ' ';
    }
    cout << endl;
  }
}