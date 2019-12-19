#pragma once

#include <string>

#include "TextQuery.h"

class TextQuery::Query {
 public:
  static Query parse(const std::string &pattern);
  QueryResult eval(const TextQuery &text_query) const;

 private:
  Query(key_type &&key);
  const key_type key_;
};
