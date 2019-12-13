#include <ostream>

#include "QueryResult.h"
#include "StrBlobPtr.h"

using std::endl, std::ostream;

using iterator = QueryResult::iterator;

// generate a result with "nullptr" if k is not found
QueryResult::QueryResult(key_type k) : sought(k) {}

// generate a concrete result if k is found
QueryResult::QueryResult(key_type k,
                         shared_lns_ptr lns_p,
                         shared_container_type text_p)
    : sought(k), lines(lns_p), file(text_p) {}

ostream &QueryResult::print(ostream &os) {
  // if keyword not found
  if (!lines) {
    return os << sought << " not found" << endl;
  }
  // if found, print the number of occurrences...
  os << sought << " occurs " << lines->size() << " time(s)\n";
  // ...and each containing line with line number
  for (const line_no ln : *lines) {
    os << "\t(line " << ln << ") " << file[ln - 1] << '\n';
  }
  return os << endl;
}

iterator QueryResult::begin() {
  return lines->begin();
}

iterator QueryResult::end() {
  return lines->end();
}

StrBlobPtr QueryResult::get_file() {
  return StrBlobPtr(file);
}
