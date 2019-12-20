#pragma once

#include <istream>
#include <map>
#include <string>
#include <utility>
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
  using record_const_iterator = record_type::const_iterator;
  TextQuery(std::istream &is);
  QueryResult query(const key_type &key) const;
  // Get a pair of iterator denoting the line-number-record of the key
  std::pair<record_const_iterator, record_const_iterator> find_key(
      const key_type &key) const;
  const shared_container_type &get_file() const;

 private:
  shared_container_type input_;
  map_type word_to_line_numbers_;
};
