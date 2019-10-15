#include <map>
#include <utility>
#include <string>
#include <iostream>
#include <vector>

using std::cout, std::endl;
using std::map;
using std::pair;
using std::string;
using std::vector;

int main() {
  map<string, vector<string>> families;

  families["Simpson"] = {"Homer", "Marge"};
  families["Simpson"].push_back("Bart");
  families["Simpson"].insert(families["Simpson"].end(), {"Lisa", "Maggie"});

  for (const pair<const string, vector<string>> &family : families) {
    cout << "The " << family.first << "s: ";
    for (const string &name : family.second) {
      cout << name << ' ';
    }
    cout << endl;
  }
}