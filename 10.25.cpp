#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <iostream>
#include <iterator>

using namespace std::placeholders;

using std::bind;
using std::cout, std::endl;
using std::ostream_iterator;
using std::partition, std::sort, std::unique;
using std::string;
using std::vector;

// return whether the length of s is greater than sz
bool check_size(const string &s, const string::size_type &sz) {
  return s.length() >= sz;
}

// return the plural version of word if ctr is greater than 1
string make_plural(const size_t &ctr,
                   const string &word,
                   const string &ending = "s") {
  return ctr > 1 ? word + ending : word;
}

void biggies(vector<string> &words, const vector<string>::size_type &sz) {
  // predicate to sort the words, by length then by dict order
  auto order_lambda = [](const string &a, const string &b) {
    return a.length() < b.length() || (a.length() == b.length() && a < b);
  };
  // sort words using pred
  sort(words.begin(), words.end(), order_lambda);

  // eliminate duplicates
  vector<string>::iterator end_unique = unique(words.begin(), words.end());
  words.erase(end_unique, words.end());

  // find first word at lease as long as sz
  vector<string>::const_iterator pos = partition(words.begin(), words.end(), bind(check_size, _1, sz));

  string::difference_type count = pos - words.cbegin();
  cout << count << ' ' << make_plural(count, "word", "s") << " of length " << sz
       << " or longer" << endl;
  copy(words.cbegin(), pos, ostream_iterator<string>(cout, " "));
}

int main() {
  vector<string> words{"the",  "quick", "red",  "fox", "jumps",
                       "over", "the",   "slow", "red", "turtle"};
  biggies(words, 6);
  cout << endl;
}