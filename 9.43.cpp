#include <algorithm>
#include <iostream>
#include <string>

using std::cout, std::endl;
using std::search;
using std::string;

void replace(string &s, const string &oldVal, const string &newVal) {
  string::const_iterator pos = s.cbegin();
  while (pos = search(pos, s.cend(), oldVal.cbegin(), oldVal.cend()),
         pos != s.cend()) {
    pos = s.erase(pos, pos + oldVal.size());
    pos = s.insert(pos, newVal.cbegin(), newVal.cend());
    pos += newVal.size();
  }
}

int main() {
  {
    string str{"To drive straight thru is a foolish, tho courageous act."};
    replace(str, "thru", "through");
    replace(str, "tho", "though");
    std::cout << str << std::endl;
  }
  {
    string str{
        "To drive straight thruthru is a foolish, thotho courageous act."};
    replace(str, "thru", "through");
    replace(str, "tho", "though");
    std::cout << str << std::endl;
  }
  {
    string str{"To drive straight thru is a foolish, tho courageous act."};
    replace(str, "thru", "thruthru");
    replace(str, "tho", "though");
    std::cout << str << std::endl;
  }
  {
    string str{"my world is a big world"};
    replace(str, "world",
            "worldddddddddddddddddddddddddddddddddddddddddddddddd");
    std::cout << str << std::endl;
  }
  return 0;
}