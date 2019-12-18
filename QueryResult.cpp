#include "QueryResult.h"

// #include <ostream>  // PCH warning: header stop not at file scope.  An
// IntelliSense PCH file was not generated.

using std::endl, std::ostream;

using QueryResult = TextQuery::QueryResult;

ostream &QueryResult::print(ostream &os) {
  // if key not found
  if (line_numbers_.empty()) {
    return os << key_ << " not found" << endl;
  }
  // if found, print the number of lines the key occurred...
  os << key_ << " occurs in " << line_numbers_.size() << " line(s)" << endl;
  // ...and each line containing the key with line number
  for (const line_number_type ln : line_numbers_) {
    os << "\t(line " << ln << ") " << input_[ln - 1] << endl;
  }
  return os << endl;
}
