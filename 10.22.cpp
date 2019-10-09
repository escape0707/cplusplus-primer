#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std::placeholders;

using std::bind;
using std::copy, std::count, std::sort, std::unique;
using std::cout, std::endl;
using std::ostream_iterator;
using std::string;
using std::vector;

// return the plural version of word if ctr is greater than 1
string make_plural(const size_t &ctr,
                   const string &word,
                   const string &ending = "s") {
  return ctr > 1 ? word + ending : word;
}

// predicate to sort the words
bool order(const string &a, const string &b) {
  return a.length() < b.length() || (a.length() == b.length() && a < b);
}

bool isLonger(const string &s, const vector<string>::size_type &sz) {
  return s.length() >= sz;
}

void biggies(vector<string> &words, const vector<string>::size_type &sz) {
  sort(words.begin(), words.end(), order);

  // eliminate duplicates
  vector<string>::iterator end_unique = unique(words.begin(), words.end());
  words.erase(end_unique, words.end());

  string::difference_type count =
      count_if(words.cbegin(), words.cend(), bind(isLonger, _1, sz));
  cout << count << ' ' << make_plural(count, "word", "s") << " of length " << sz
       << " or longer" << endl;
}

int main() {
  vector<string> words{"the",  "quick", "red",  "fox", "jumps",
                       "over", "the",   "slow", "red", "turtle"};
  biggies(words, 6);
}
