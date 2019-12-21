#pragma once

#include <memory>
#include <string>

#include "BinaryRange.h"
#include "LineNumberRange.h"
#include "TextQuery.h"

class AndRange : public BinaryRange {
 public:
  AndRange(const std::shared_ptr<LineNumberRange> &p_lhs,
           const std::shared_ptr<LineNumberRange> &p_rhs);
  record_type eval(const TextQuery &text_query) const override;
};
