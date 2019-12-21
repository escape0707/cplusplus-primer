#pragma once

#include <memory>
#include <string>

#include "ByKeyRange.h"
#include "TextQuery.h"

class TextQuery::Query {
 public:
  static Query parse(const std::string &pattern);
  QueryResult eval(const TextQuery &text_query) const;

 private:
  Query(key_type &&key);
  std::unique_ptr<LineNumberRange> p_range_;
};
