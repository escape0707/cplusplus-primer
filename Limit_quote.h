#include <cstddef>
#include <string>

#include "Disc_quote.h"

class Limit_quote : Disc_quote {
 public:
  Limit_quote();
  Limit_quote(const std::string &book, double p, std::size_t qty, double disc);
  double net_price(std::size_t cnt) const override;
};
