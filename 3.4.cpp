#include <iostream>
#include <string>
using std::cin, std::cout, std::endl;
using std::string;

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  if (s1 == s2) {
    cout << "s1 and s2 are equal" << endl;
  } else if (s1 > s2) {
    cout << "s1 is larger" << endl;
  } else {
    cout << "s2 is larger" << endl;
  }

  if (s1.length() == s2.length()) {
    cout << "s1 and s2 have the same length" << endl;
  } else if (s1.length() > s2.length()) {
    cout << "s1 is longer" << endl;
  } else {
    cout << "s2 is longer" << endl;
  }
}