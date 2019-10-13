#include <exception>
#include <fstream>
#include <iostream>
#include <istream>
#include <iterator>
#include <map>
#include <sstream>
#include <string>
#include <utility>

using std::as_const, std::move;
using std::cout, std::endl;
using std::getline, std::string;
using std::ifstream;
using std::istream_iterator;
using std::istringstream;
using std::map;
using std::runtime_error;
using std::ws;

// Build a map<string, string> from info given by ifstream is.
map<string, string> buildMap(ifstream &is) {
  map<string, string> ret;
  for (string key, value; is >> key >> ws && getline(is, value);) {
    ret[std::move(key)] = std::move(value);  // add the mapping
  }
  return ret;  // NRVO: Named Return Value Optimization allowed here
}

// Transform string s according to map m.
const string &transform(const string &s, const map<string, string> &m) {
  map<string, string>::const_iterator map_it = m.find(s);  // find s in m
  if (map_it == m.cend()) {                                // if not found
    return s;
  } else {
    return map_it->second;  // return the replacement word
  }
}

// Transform text in input using map_file.
void word_transform(ifstream &input, ifstream &map_file) {
  // Interpreted map info which describes a transform.
  map<string, string> trans_map = buildMap(map_file);
  istringstream iss;
  for (string line; getline(input, line);) {  // process line by line
    iss.str(line);
    iss.clear();
    // print the first word in the line
    istream_iterator<string> it(iss), eof;
    if (it != eof) {
      cout << transform(*it++, trans_map);
    }
    // print others separated by space
    while (it != eof) {
      cout << ' ' << transform(*it++, trans_map);
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
  word_transform(text_in, map_in);
}
