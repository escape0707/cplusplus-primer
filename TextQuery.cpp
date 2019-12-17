#include "TextQuery.h"

#include <istream>
#include <iterator>
#include <sstream>
#include <string>
#include <utility>

#include "QueryResult.h"

using std::getline, std::initializer_list, std::string;
using std::istream;
using std::istream_iterator;
using std::istringstream;

using QueryResult = TextQuery::QueryResult;

TextQuery::TextQuery(istream &is) {
  // default constructed input_ and word_to_line_numbers_
  istringstream iss;
  string s;
  // process lines from in-stream one by one, keep track of line number
  for (line_number_type ln = 1; getline(is, s); ++ln) {
    iss.str(s);
    iss.clear();
    // process keys from line one by one
    for (istream_iterator<key_type> beg(iss), end; beg != end; ++beg) {
      // look for key in word_to_line_numbers_
      map_type::iterator lower = word_to_line_numbers_.lower_bound(*beg);
      if (lower->first != *beg) {  // if not found, emplace {key, {ln}}
        word_to_line_numbers_.emplace_hint(
            lower, *beg, initializer_list<line_number_type>{ln});
      } else if (lower->second.back() != ln) {  // else if found in a new line
        lower->second.push_back(ln);
      }
    }
    // move append current line to shared container
    input_.push_back(std::move(s));
  }
}

QueryResult TextQuery::query(const key_type &key) const {
  const map_type::const_iterator &result = word_to_line_numbers_.find(key);
  if (result ==
      word_to_line_numbers_.cend()) {  // not found, use simple constructor
    return QueryResult(key);
  } else {  // found, use detailed constructor
    return QueryResult(key, result->second, input_);
  }
}
