#pragma once

#include "TextQuery.h"

class TextQuery::Query {
 public:
  Query(const key_type &key);
  QueryResult eval(const TextQuery &text_query) const;

 private:
  const key_type key_;
};
