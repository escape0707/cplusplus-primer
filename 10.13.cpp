#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::copy, std::partition;
using std::ostream_iterator;
using std::string;
using std::vector;

bool five_or_more(const string &s) {
  return s.length() >= 5;
}

int main() {
  vector<string> words{"the",  "quick", "red",  "fox", "jumps",
                       "over", "the",   "slow", "red", "turtle"};
  vector<string>::const_iterator part_pos(
      partition(words.begin(), words.end(), five_or_more));
  copy(part_pos, words.cend(), ostream_iterator<string>(cout, " "));
  cout << endl;
}
