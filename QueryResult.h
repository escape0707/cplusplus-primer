#pragma once

#include <iostream>

#include "TextQuery.h"

// QueryResult saves its own copy of shared_container (of inputted text) and
// key's line number record, and is able to print even after TextQuery get
// destroyed
class TextQuery::QueryResult {
 public:
  template <typename... Args>
  QueryResult(key_type &&key,
              const shared_container_type &input,
              Args &&... args);
  std::ostream &print(std::ostream &os = std::cout);

 private:
  key_type key_;
  shared_container_type input_;
  record_type line_numbers_;
};

#include "QueryResult.tpp"
