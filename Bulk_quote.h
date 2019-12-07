#pragma once

#include <cstddef>
#include <string>

#include "Quote.h"

class Bulk_quote : public Quote {
 public:
  Bulk_quote();
  Bulk_quote(const std::string &book, double p, std::size_t qty, double disc);
  double net_price(std::size_t) const override;
  void debug() const override;

 private:
  std::size_t min_qty = 0;
  double discount = 0.0;
};
