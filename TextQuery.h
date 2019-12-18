#pragma once

#include <istream>
#include <map>
#include <memory>
#include <vector>

#include "StrBlob.h"

class TextQuery {
 public:
  class QueryResult;
  using shared_container_type = StrBlob;
  using key_type = shared_container_type::value_type;
  using line_number_type = shared_container_type::size_type;
  using map_type = std::map<key_type, std::shared_ptr<std::vector<line_number_type>>>;
  TextQuery(std::istream &is);
  QueryResult query(const key_type &key) const;

 private:
  shared_container_type input_;
  map_type word_to_p_line_numbers_;
};
