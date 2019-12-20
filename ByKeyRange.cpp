#include "ByKeyRange.h"

#include <string>
#include <utility>

#include "TextQuery.h"

using std::pair;
using std::string;

using ByKeyRange = TextQuery::ByKeyRange;
using record_type = TextQuery::record_type;

ByKeyRange::ByKeyRange(key_type &&key) : key_(std::move(key)) {}

string ByKeyRange::rep() const {
  return key_;
}

record_type ByKeyRange::eval(const TextQuery &text_query) const {
  pair<record_const_iterator, record_const_iterator> p =
      text_query.find_key(key_);
  return record_type(p.first, p.second);
}
