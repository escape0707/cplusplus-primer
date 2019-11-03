#include <fstream>
#include <iterator>
#include <sstream>
#include <string>
#include <utility>

#include "QueryResult.h"
#include "TextQuery.h"

using std::getline, std::string;
using std::ifstream;
using std::istream_iterator;
using std::istringstream;

// constructor from ifstream
TextQuery::TextQuery(ifstream &fin)
    : text_ptr(new shared_container_ptr::element_type) {
  istringstream iss;
  string s;
  // process lines from fin one by one, and track line number
  for (line_no ln = 1; getline(fin, s); ++ln) {
    iss.str(s);
    iss.clear();
    // process words from line one by one
    for (istream_iterator<key_type> beg(iss), end; beg != end; ++beg) {
      const map_type::iterator result = index.find(*beg);
      if (result == index.end()) {  // emplace <key, {ln}> if not found
        index.emplace(*beg, new map_type::mapped_type::element_type{ln});
      } else if (result->second->back() != ln) {  // else if new ln, push_back()
        result->second->push_back(ln);
      }
    }
    // move append current line to shared container
    text_ptr->push_back(std::move(s));
  }
}

// return a QueryResult of keyword
QueryResult TextQuery::query(const key_type &keyword) const {
  const map_type::const_iterator result = index.find(keyword);
  if (result == index.cend()) {  // not found, use simple constructor
    return QueryResult(keyword);
  } else {  // found, use detailed constructor
    return QueryResult(keyword, result->second, text_ptr);
  }
}
