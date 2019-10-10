#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int main() {
  vector<string> text{"Hello, ", "world!", "", "Hi, ", "you!"};
  // print each line in text up to the first blank line
  for (vector<string>::iterator it = text.begin();
       it != text.end() && !it->empty(); ++it) {
    for (char &c : *it) {
      c = toupper(c);
    }
  }

  for (const string &str : text) {
    cout << str << endl;
  }
}
