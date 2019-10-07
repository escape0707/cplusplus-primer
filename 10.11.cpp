#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::copy, std::sort, std::stable_sort, std::unique;
using std::ostream_iterator;
using std::string;
using std::vector;

bool isShorter(const string &s1, const string &s2) {
  return s1.size() < s2.size();
}

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

  stable_sort(words.begin(), words.end(), isShorter);

  copy(words.cbegin(), words.cend(), ostream_iterator<string>(cout, " "));
  cout << endl;
}
