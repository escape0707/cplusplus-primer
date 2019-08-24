#include <iostream>
#include <string>

using std::cin, std::cout, std::endl;
using std::string;

int main() {
  string s;
  if (cin >> s) {
    for (const char &c : s) {
      if (!ispunct(c)) {
        cout << c;
      }
    }
    cout << endl;
  }

  return 0;
}
