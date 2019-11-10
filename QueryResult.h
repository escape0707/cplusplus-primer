#pragma once

#include <iostream>
#include <memory>

#include "StrBlobPtr.h"
#include "TextQuery.h"

// QueryResult saves its own copy of shared_ptrs to use data even if TextQuery
// is destroyed
class QueryResult {
 public:
  using key_type = TextQuery::key_type;
  using shared_container_type = TextQuery::shared_container_type;
  using shared_lns_ptr = TextQuery::map_type::mapped_type;
  using line_no = TextQuery::line_no;
  using iterator = shared_lns_ptr::element_type::iterator;
  QueryResult(key_type keyword);
  QueryResult(key_type keyword,
              shared_lns_ptr lns_ptr,
              shared_container_type text_ptr);
  std::ostream &print(std::ostream &os = std::cout);
  iterator begin();
  iterator end();
  StrBlobPtr get_file();

 private:
  key_type sought;
  shared_lns_ptr lines;
  shared_container_type file;
};
