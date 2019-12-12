#include "Bulk_quote.h"

#include <cstddef>
#include <iostream>
#include <string>

using std::cout;
using std::size_t;
using std::string;

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
