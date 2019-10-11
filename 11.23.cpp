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
  families.emplace("Simpson", "Bart");
  families.insert({{"Simpson", "Lisa"}, {"Simpson", "Maggie"}});

  {
    string family_name;
    for (multimap<string, string>::const_iterator beg = families.cbegin(),
                                                  end = families.cend();
         beg != end; ++beg) {
      if (beg->first != family_name) {
        cout << "\nThe " << (family_name = beg->first) << "s: ";
      }
      cout << beg->second << ' ';
    }
    cout << endl;
  }
}