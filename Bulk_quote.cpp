#include <cstddef>
#include <iostream>
#include <string>

#include "Bulk_quote.h"

using std::cout;
using std::size_t;
using std::string;

Bulk_quote::Bulk_quote() = default;

Bulk_quote::Bulk_quote(const string &book, double p, size_t qty, double disc)
    : Disc_quote(book, p, qty, disc) {}

double Bulk_quote::net_price(size_t cnt) const {
  if (cnt >= quantity) {
    return cnt * (1 - discount) * price;
  }
  return cnt * price;
}

void Bulk_quote::debug() const {
  Quote::debug();
  cout << ", min_qty: " << quantity << ", discount: " << discount;
}
