#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::istream_iterator;
using std::string;
using std::vector;

int main() {
  vector<string> words((istream_iterator<string>(cin)),
                       istream_iterator<string>());

  unsigned printed = 0;  // Count of words printed in current line.
  for (string &word : words) {
    if (printed++ == 8) {
      cout << endl;
      printed = 1;  // simplification of printed %= 8
    }
    for (char &c : word) {
      c = toupper(c);
    }
    cout << word << ' ';
  }
  cout << endl;
}
