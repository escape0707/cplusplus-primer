#pragma once

#include <memory>
#include <string>

#include "LineNumberRange.h"
#include "TextQuery.h"

class AndRange : public LineNumberRange {
 public:
  AndRange(const std::shared_ptr<LineNumberRange> &p_lhs,
           const std::shared_ptr<LineNumberRange> &p_rhs);
  std::string rep() const override;
  record_type eval(const TextQuery &text_query) const override;

 private:
  std::shared_ptr<LineNumberRange> p_lhs_, p_rhs_;
};
