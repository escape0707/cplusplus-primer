#ifndef QUERYRESULT
#define QUERYRESULT

#include <iostream>
#include <memory>

#include "TextQuery.h"

// QueryResult saves its own copy of shared_ptrs to use data even if TextQuery
// is destroyed
class QueryResult {
 public:
  using key_type = TextQuery::key_type;
  using shared_container_ptr = TextQuery::shared_container_ptr;
  using shared_lns_ptr = TextQuery::map_type::mapped_type;
  using line_no = TextQuery::line_no;
  QueryResult(key_type keyword);
  QueryResult(key_type keyword,
              shared_lns_ptr lns_ptr,
              shared_container_ptr text_ptr);
  std::ostream &print(std::ostream &os = std::cout);

 private:
  key_type sought;
  shared_lns_ptr lines;
  shared_container_ptr file;
};

#endif
