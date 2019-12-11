#pragma once

#include <cstddef>
#include <string>

#include "Quote.h"

class Disc_quote : public Quote {
 public:
  Disc_quote();
  Disc_quote(const std::string &book,
             double price,
             std::size_t qty,
             double disc);
  Disc_quote(const Disc_quote &other);
  Disc_quote(Disc_quote &&other);
  Disc_quote &operator=(const Disc_quote &other);
  Disc_quote &operator=(Disc_quote &&other);
  ~Disc_quote() override;
  double net_price(std::size_t) const override = 0;

 protected:
  std::size_t quantity = 0;
  double discount = 0.0;
};
