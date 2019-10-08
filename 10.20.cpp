#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <utility>
#include <vector>

using std::as_const;
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

void biggies(vector<string> &words, const vector<string>::size_type &sz) {
  // predicate to sort the words
  auto order_lambda = [](const string &a, const string &b) {
    return a.length() < b.length() || (a.length() == b.length() && a < b);
  };
  sort(words.begin(), words.end(), order_lambda);

  // eliminate duplicates
  vector<string>::iterator end_unique = unique(words.begin(), words.end());
  words.erase(end_unique, words.end());

  string::difference_type count = count_if(
      words.cbegin(), words.cend(),
      [&sz = as_const(sz)](const string &s) { return s.length() >= sz; });
  cout << count << ' ' << make_plural(count, "word", "s") << " of length " << sz
       << " or longer" << endl;
}

int main() {
  vector<string> words{"the",  "quick", "red",  "fox", "jumps",
                       "over", "the",   "slow", "red", "turtle"};
  biggies(words, 6);
}
