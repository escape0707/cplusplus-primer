#pragma once

#include <istream>
#include <map>
#include <vector>

#include "StrBlob.h"

class TextQuery {
 public:
  class QueryResult;
  using shared_container_type = StrBlob;
  using key_type = shared_container_type::value_type;
  using line_number_type = shared_container_type::size_type;
  using record_type = std::vector<line_number_type>;
  using map_type = std::map<key_type, record_type>;
  TextQuery(std::istream &is);
  QueryResult query(const key_type &key) const;

 private:
  shared_container_type input_;
  map_type word_to_line_numbers_;
};
