#include <cstddef>
#include <string>

#include "Quote.h"

class Limit_quote : Quote {
 public:
  Limit_quote();
  Limit_quote(const std::string &book, double p, std::size_t qty, double disc);
  double net_price(std::size_t cnt) const override;

 private:
  std::size_t max_qty = 0;
  double discount = 0.0;
};
