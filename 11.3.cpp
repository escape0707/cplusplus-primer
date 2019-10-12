#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <string>
#include <utility>

using std::cin, std::cout, std::endl;
using std::istream_iterator, std::ostream_iterator;
using std::map;
using std::pair;
using std::set;
using std::string;

int main() {
  map<string, size_t> word_count;
  set<string> exclude = {"The", "But", "And", "Or", "An", "A",
                         "the", "but", "and", "or", "an", "a"};

  for (istream_iterator<string> it(cin), eof; it != eof; ++it) {
    if (exclude.find(*it) == exclude.cend()) {
      ++word_count[*it];
    }
  }

  for (const pair<const string, size_t> &p : word_count) {
    cout << p.first << " occurs " << p.second
         << (p.second > 1 ? " times" : " time") << endl;
  };
}