#include "QueryResult.h"

#include <ostream>

using std::endl, std::ostream;

QueryResult::QueryResult(const key_type &key) : key_(key) {}
// default construct p_line_numbers_ and input_ to be empty

QueryResult::QueryResult(const key_type &key,
                         const shared_lns_ptr &p_line_numbers,
                         const shared_container_type &input)
    : key_(key), p_line_numbers_(p_line_numbers), input_(input) {}

ostream &QueryResult::print(ostream &os) {
  // if key not found
  if (!p_line_numbers_) {
    return os << key_ << " not found" << endl;
  }
  // if found, print the number of lines the key occurred...
  os << key_ << " occurs in " << p_line_numbers_->size() << " line(s)" << endl;
  // ...and each line containing the key with line number
  for (const line_number_type ln : *p_line_numbers_) {
    os << "\t(line " << ln << ") " << input_[ln - 1] << endl;
  }
  return os << endl;
}
