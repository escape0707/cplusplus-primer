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
    : Disc_quote(book, p, qty, disc) {}

double Limit_quote::net_price(std::size_t cnt) const {
  if (cnt <= quantity) {
    return cnt * (1 - discount) * price;
  }
  return quantity * (1 - discount) * price + (cnt - quantity) * price;
}
