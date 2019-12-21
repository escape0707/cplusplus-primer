#pragma once

#include <memory>
#include <string>

#include "ByKeyRange.h"
#include "TextQuery.h"

class TextQuery::Query {
  friend Query operator~(const Query &rhs);
  friend Query operator&(const Query &lhs, const Query &rhs);
  friend Query operator|(const Query &lhs, const Query &rhs);

 public:
  static Query parse(const std::string &pattern);
  QueryResult eval(const TextQuery &text_query) const;

 private:
  Query(key_type &&key);
  // Only used by operators to create a new Query with a new LineNumberRange.
  Query(std::shared_ptr<LineNumberRange> &&p_range);
  std::shared_ptr<LineNumberRange> p_range_;
};
