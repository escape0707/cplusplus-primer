#include <fstream>
#include <iostream>
#include <iterator>
#include <random>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using std::as_const;
using std::cout, std::endl;
using std::default_random_engine;
using std::getline, std::string;
using std::ifstream;
using std::istream_iterator;
using std::istringstream;
using std::random_device;
using std::runtime_error;
using std::uniform_int_distribution;
using std::unordered_map;
using std::vector;

using map_type = unordered_map<string, vector<string>>;

static map_type build_map(ifstream &is) {
  map_type ret;
  for (string key, value; is >> key;) {
    if (is.get() == ' ' && getline(is, value)) {
      ret[std::move(key)].push_back(std::move(value));
    } else {
      throw runtime_error("Can't parse mapping rule for " + key);
    }
  }
  return ret;
}

static const string &random_transform(const string &s, const map_type &m) {
  static random_device rd;
  static default_random_engine e(rd());
  static uniform_int_distribution<> u;
  const map_type::const_iterator map_it = m.find(s);
  if (map_it == m.cend()) {
    return s;
  } else {
    const vector<string> &replacement_cadidate_collection = map_it->second;
    const int length = size(replacement_cadidate_collection);
    uniform_int_distribution<>::param_type random_range(0, length - 1);  // When 0 > length - 1, the behavior is undefined.
    return replacement_cadidate_collection[u(e, random_range)];
  }
}

static void word_transform(ifstream &input, const map_type &trans_map) {
  istringstream iss;
  for (string line; getline(input, line);) {
    iss.str(line);
    iss.clear();
    istream_iterator<string> s_it(iss), eof;
    if (s_it != eof) {
      cout << random_transform(*s_it, trans_map);
    }
    while (++s_it != eof) {
      cout << ' ' << random_transform(*s_it, trans_map);
    }
    cout << endl;
  }
}

int main() {
  ifstream map_in("m.in");   // Map info.
  ifstream text_in("a.in");  // Text to transform.

  if (!(map_in && text_in)) {
    throw runtime_error("Can't open files.");
  }
  const map_type trans_map = build_map(map_in);
  word_transform(text_in, trans_map);
}
