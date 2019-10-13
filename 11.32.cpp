// use a set with pair<string, string> is a better solution

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using std::copy;
using std::cout, std::endl, std::ostream;
using std::multimap;
using std::pair;
using std::string;
using std::vector;

// Print a vector.
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (const string &elem : v) {
    os << elem << ' ';
  }
  return os;
}

int main() {
  // Map from author to work.
  multimap<string, string> authors = {
      {"A", "C"},       {"A", "B"},        {"A", "D"},
      {"Andy", "Book"}, {"Andy", "Candy"}, {"Andy", "Apple"},
      {"Dad", "3"},     {"Dad", "1"},      {"Dad", "2"}};

  if (!authors.empty()) {
    string author = authors.cbegin()->first;
    vector<string> works;
    // Sort and print author name with works names.
    auto print = [&] {
      sort(works.begin(), works.end());
      cout << author << ": " << works << endl;
    };
    for (const pair<const string, string> &p : authors) {
      // if run into a new author's data, print and reset author and works cache
      if (author != p.first) {
        print();
        author = p.first;
        works.clear();
      }
      works.push_back(p.second);  // push the new work info
    }
    print();  // print the last author-works data
  }
}
