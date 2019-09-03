#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int main() {
  do {
    cout << "Please enter two strings: " << endl;
    string s1, s2;
    if (cin >> s1 >> s2) {
      cout << "s1 is " << (s1 < s2 ? "less" : "more") << " than s2.\n" << endl;
    }
  } while (cin);

  return 0;
}
