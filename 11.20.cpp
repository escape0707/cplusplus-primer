#include <iostream>
#include <map>
#include <string>
#include <utility>

using std::cin, std::cout, std::endl;
using std::map;
using std::pair;
using std::string;

int main() {
  map<string, size_t> word_count;
  for (string word; cin >> word;) {
    pair<map<string, size_t>::iterator, bool> p = word_count.insert({word, 1});
    if (!p.second) {  // word is already in word_count
      ++p.first->second;
    }
  }

  for (const pair<string, size_t> &p : word_count) {
    cout << p.first << " occurs " << p.second
         << (p.second > 1 ? " times" : " time") << endl;
  };
}