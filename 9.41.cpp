#include <iostream>
#include <string>
#include <vector>

using std::cout, std::endl;
using std::string;
using std::vector;

int main() {
  string origin("Hello, world!");
  vector<char> v(origin.cbegin(), origin.cend());

  string s(v.cbegin(), v.cend());
  cout << s << endl;
}