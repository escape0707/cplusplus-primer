#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <utility>

using std::cout, std::endl;
using std::ifstream;
using std::istream_iterator;
using std::istringstream;
using std::pair;
using std::runtime_error;
using std::string;
using std::unordered_map;

void word_count() {
  ifstream words_in("w.in");
  unordered_map<string, size_t> word_count;
  for (string word; words_in >> word;) {
    ++word_count[word];
  }
  for (const pair<const string, size_t> &p : word_count) {
    cout << p.first << " occurs " << p.second << " time"
         << (p.second > 1 ? "s" : "") << endl;
  }
}

inline const string &transform(const string &s,
                               const unordered_map<string, string> &m) {
  unordered_map<string, string>::const_iterator it = m.find(s);
  if (it == m.cend()) {
    return s;
  } else {
    return it->second;
  }
}

void word_transform() {
  ifstream map_file("m.in"), input("a.in");
  unordered_map<string, string> trans_map;
  for (string key, value; map_file >> key;) {
    if (map_file.get() == ' ' && getline(map_file, value)) {
      // staring from C++17, use try_emplace()
      trans_map.emplace(std::move(key), std::move(value));
    } else {
      throw runtime_error("No rule for " + key);
    }
  }
  istringstream iss;
  for (string text; getline(input, text);) {
    iss.str(text);
    iss.clear();
    istream_iterator<string> it(iss), eof;
    if (it != eof) {
      cout << transform(*it, trans_map);
    }
    while (++it != eof) {
      cout << ' ' << transform(*it, trans_map);
    }
    cout << endl;
  }
}

int main() {
  word_count();
  word_transform();
}