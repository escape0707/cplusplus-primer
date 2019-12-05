#include <cstddef>
#include <string>

#include "Limit_quote.h"

using std::size;
using std::string;

Limit_quote::Limit_quote() = default;

Limit_quote::Limit_quote(const std::string &book,
                         double p,
                         std::size_t qty,
                         double disc)
    : Quote(book, p), max_qty(qty), discount(disc) {}

double Limit_quote::net_price(std::size_t cnt) const {
  if (cnt <= max_qty) {
    return cnt * (1 - discount) * price;
  }
  return max_qty * (1 - discount) * price + (cnt - max_qty) * price;
}
