#pragma once

#include <memory>
#include <string>

#include "LineNumberRange.h"
#include "TextQuery.h"

class BinaryRange : public LineNumberRange {
 public:
  BinaryRange(const std::shared_ptr<LineNumberRange> &p_lhs,
              const std::shared_ptr<LineNumberRange> &p_rhs,
              std::string op);
  std::string rep() const override;

 protected:
  std::shared_ptr<LineNumberRange> p_lhs_, p_rhs_;

 private:
  std::string op_;
};
