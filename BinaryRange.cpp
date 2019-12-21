#include "BinaryRange.h"

#include <memory>
#include <string>

using std::shared_ptr;
using std::string;

BinaryRange::BinaryRange(const shared_ptr<LineNumberRange> &p_lhs,
                         const shared_ptr<LineNumberRange> &p_rhs,
                         string op)
    : p_lhs_(p_lhs), p_rhs_(p_rhs), op_(op) {}

string BinaryRange::rep() const {
  return "(" + p_lhs_->rep() + " " + op_ + " " + p_rhs_->rep() + ")";
}
