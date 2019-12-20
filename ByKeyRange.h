#pragma once

#include <string>

#include "TextQuery.h"

class TextQuery::ByKeyRange {
 public:
  ByKeyRange(key_type &&key);
  std::string rep() const;
  record_type eval(const TextQuery &text_query) const;

 private:
  key_type key_;
};
