#pragma once

#include <string>

#include "LineNumberRange.h"
#include "TextQuery.h"

class ByKeyRange : public LineNumberRange {
 public:
  using key_type = TextQuery::key_type;
  ByKeyRange(key_type &&key);
  std::string rep() const override;
  record_type eval(const TextQuery &text_query) const override;

 private:
  key_type key_;
};
