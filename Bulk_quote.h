#pragma once

#include <cstddef>
#include <string>

#include "Disc_quote.h"

class Bulk_quote : public Disc_quote {
 public:
  Bulk_quote();
  Bulk_quote(const std::string &book, double p, std::size_t qty, double disc);
  double net_price(std::size_t) const override;
  void debug() const override;
};
