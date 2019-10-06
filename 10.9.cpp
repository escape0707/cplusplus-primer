#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::copy, std::sort, std::unique;
using std::ostream_iterator;
using std::string;
using std::vector;

void elimDups(vector<string> &svec) {
  sort(svec.begin(), svec.end());
  vector<string>::iterator end_unique = unique(svec.begin(), svec.end());

  copy(svec.cbegin(), svec.cend(), ostream_iterator<string>(cout, " "));
  cout << endl;

  svec.erase(end_unique, svec.end());
}

int main() {
  vector<string> words{"the",  "quick", "red",  "fox", "jumps",
                       "over", "the",   "slow", "red", "turtle"};

  elimDups(words);

  copy(words.cbegin(), words.cend(), ostream_iterator<string>(cout, " "));
  cout << endl;
}
