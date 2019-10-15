#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using std::cout, std::endl;
using std::multimap;
using std::pair;
using std::string;
using std::vector;

int main() {
  multimap<string, string> families;

  families.insert({{"Simpson", "Homer"}, {"Simpson", "Marge"}});
  families.insert({{"Tom", "Alice"}, {"Tom", "Bob"}});
  families.insert({{"Simpson", "Lisa"}, {"Simpson", "Maggie"}});
  families.emplace("Tom", "Catte");
  families.insert({{"Tom", "Dog"}, {"Tom", "Emma"}});
  families.emplace("Simpson", "Bart");

  {
    string family_name;
    multimap<string, string>::const_iterator beg = families.cbegin(),
                                             end = families.cend();
    if (beg != end) {
      cout << "The " << (family_name = beg->first) << "s: " << beg->second;
    }
    while (++beg != end) {
      if (family_name != beg->first) {
        cout << "\nThe " << (family_name = beg->first) << "s:";
      }
      cout << ' ' << beg->second;
    }
    cout << endl;
  }
}