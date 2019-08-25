#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int main() {
  vector<string> words;
  string word;
  while (cin >> word) {
    words.push_back(word);
  }

  unsigned printed = 0;  // holds count of words printed in current line
  for (auto &word : words) {
    if (printed++ == 8) {
      cout << endl;
      printed = 1;  // simplification of printed %= 8
    }
    for (auto &c : word) {
      c = toupper(c);
    }
    cout << word << ' ';
  }
  cout << endl;

  return 0;
}
