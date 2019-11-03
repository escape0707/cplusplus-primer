#include <ostream>

#include "QueryResult.h"

using std::endl, std::ostream;

// generate a result with "nullptr" if k is not found
QueryResult::QueryResult(key_type k) : keyword(k) {}

// generate a concrete result if k is found
QueryResult::QueryResult(key_type k,
                         shared_lns_ptr lns_p,
                         shared_container_ptr text_p)
    : keyword(k), lns_ptr(lns_p), text_ptr(text_p) {}

ostream &QueryResult::print(ostream &os) {
  // if keyword not found
  if (lns_ptr == nullptr || text_ptr == nullptr) {
    return os << keyword << " not found" << endl;
  }
  // if found, print the number of occurrences...
  os << keyword << " occurs " << lns_ptr->size() << " times\n";
  // ...and each containing line with line number
  for (const line_no ln : *lns_ptr) {
    os << "\t(line " << ln << ") " << (*text_ptr)[ln - 1] << '\n';
  }
  return os << endl;
}
