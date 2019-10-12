// set find element faster

#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <utility>
#include <vector>

using std::cin, std::cout, std::endl;
using std::find;
using std::istream_iterator, std::ostream_iterator;
using std::map;
using std::pair;
using std::string;
using std::vector;

int main() {
  map<string, size_t> word_count;
  vector<string> exclude = {"The", "But", "And", "Or", "An", "A",
                            "the", "but", "and", "or", "an", "a"};

  for (istream_iterator<string> it(cin), eof; it != eof; ++it) {
    if (find(exclude.cbegin(), exclude.cend(), *it) == exclude.cend()) {
      // if (exclude.find(*it) == exclude.cend()) {
      ++word_count[*it];
    }
  }

  for (const pair<const string, size_t> &p : word_count) {
    cout << p.first << " occurs " << p.second
         << (p.second > 1 ? " times" : " time") << endl;
  };
}
