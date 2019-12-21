#pragma once

#include <string>

#include "TextQuery.h"

class LineNumberRange {
 public:
  using record_type = TextQuery::record_type;
  using record_const_iterator = TextQuery::record_const_iterator;
  using line_number_type = record_type::value_type;
  virtual std::string rep() const = 0;
  virtual record_type eval(const TextQuery &text_query) const = 0;
  virtual ~LineNumberRange();
};
