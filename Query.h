#pragma once

#include <string>

#include "ByKeyRange.h"
#include "TextQuery.h"

class TextQuery::Query {
 public:
  static Query parse(const std::string &pattern);
  QueryResult eval(const TextQuery &text_query) const;

 private:
  Query(key_type &&key);
  ByKeyRange range_;
};
