#pragma once

#include <cstddef>

#include "Disc_quote.h"

class Bulk_quote : public Disc_quote {
  using Disc_quote::Disc_quote;

 public:
  double net_price(std::size_t) const override;
  void debug() const override;
  Bulk_quote *clone() const & override;
  Bulk_quote *clone() && override;
};
