#pragma once

#include <iostream>

#include "TextQuery.h"

// QueryResult saves its own copy of shared_container (of inputted text) and
// key's line number record, and is able to print even after TextQuery get
// destroyed
class TextQuery::QueryResult {
 public:
  // Construct an empty QueryResult when the key is not found
  QueryResult(const key_type &key);
  // Construct a concrete QueryResult when key is found
  QueryResult(const key_type &key,
              const record_type &line_numbers,
              const shared_container_type &input);
  std::ostream &print(std::ostream &os = std::cout);

 private:
  key_type key_;
  record_type line_numbers_;
  shared_container_type input_;
};
