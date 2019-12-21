#pragma once

#include <memory>
#include <string>

#include "LineNumberRange.h"
#include "TextQuery.h"

class NotRange : public LineNumberRange {
 public:
  NotRange(const std::shared_ptr<LineNumberRange> &p_rhs);
  std::string rep() const override;
  record_type eval(const TextQuery &text_query) const override;

 private:
  std::shared_ptr<LineNumberRange> p_rhs_;
};
