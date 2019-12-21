#include "NotRange.h"

#include <string>

using std::string;

using record_type = NotRange::record_type;

NotRange::NotRange(const std::shared_ptr<LineNumberRange> &p_rhs)
    : p_rhs_(p_rhs) {}

string NotRange::rep() const {
  return "~(" + p_rhs_->rep() + ")";
}

record_type NotRange::eval(const TextQuery &text_query) const {
  record_type ret;
  const record_type &rhs = p_rhs_->eval(text_query);
  record_const_iterator beg = rhs.cbegin();
  const record_const_iterator end = rhs.cend();
  const line_number_type total = text_query.get_file().size();
  line_number_type curr = 1;
  for (; curr <= total; ++curr) {
    if (beg == end) {
      break;
    }
    if (*beg == curr) {
      ++beg;
      continue;
    }
    ret.push_back(curr);
  }
  while (curr <= total) {
    ret.push_back(curr++);
  }
  return ret;
}
