#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int main() {
  string s = "word";
  string pl = s + ((s[s.size() - 1] == 's') ? "" : "s");
  // pl = s + s[s.size() - 1] == 's' ? "" : "s";
  // pl = ((s + s[s.size() - 1]) == 's') ? "" : "s";
  cout << pl << endl;


}
