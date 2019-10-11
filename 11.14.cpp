#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using std::cout, std::endl;
using std::map;
using std::pair;
using std::string;
using std::vector;

int main() {
  map<string, vector<pair<string, string>>> families;

  families["Simpson"] = {{"Homer", "1900-1-1"}, {"Marge", "1900-1-1"}};
  families["Simpson"].emplace_back("Bart", "1900-1-1");
  families["Simpson"].insert(families["Simpson"].end(),
                             {{"Lisa", "1900-1-1"}, {"Maggie", "1900-1-1"}});

  for (const pair<string, vector<pair<string, string>>> &family : families) {
    cout << "The " << family.first << "s:\n";
    for (const pair<string, string> &child : family.second) {
      cout << child.first << " born at " << child.second << endl;
    }
  }
}
