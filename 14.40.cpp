#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <utility>
#include <vector>

using std::as_const;
using std::copy, std::find_if, std::sort, std::unique;
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

class judge {
 public:
  judge(size_t sz) : sz(sz) {}
  bool operator()(const string &s) { return s.length() >= sz; }

 private:
  size_t sz;
};

void biggies(vector<string> &words, const vector<string>::size_type &sz) {
  // predicate to sort the words
  auto order_lambda = [](const string &a, const string &b) {
    return a.length() < b.length() || (a.length() == b.length() && a < b);
  };
  sort(words.begin(), words.end(), order_lambda);

  // eliminate duplicates
  vector<string>::iterator end_unique = unique(words.begin(), words.end());
  words.erase(end_unique, words.end());

  // find first word longer than sz
  vector<string>::const_iterator pos =
      find_if(words.cbegin(), words.cend(), judge(sz));

  string::difference_type count = words.cend() - pos;
  cout << count << ' ' << make_plural(count, "word", "s") << " of length " << sz
       << " or longer" << endl;
  copy(pos, words.cend(), ostream_iterator<string>(cout, " "));
}

int main() {
  vector<string> words{"the",  "quick", "red",  "fox", "jumps",
                       "over", "the",   "slow", "red", "turtle"};
  biggies(words, 5);
  cout << endl;
}
