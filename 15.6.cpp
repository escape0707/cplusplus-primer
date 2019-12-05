#include <cstddef>
#include <iostream>

#include "Bulk_quote.h"
#include "Quote.h"

using std::cout, std::endl, std::ostream;
using std::size_t;

static double print_total(ostream &os, const Quote &item, size_t n) {
  double ret = item.net_price(n);
  os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret
     << endl;
  return ret;
}

int main() {
  Quote q("C++ Primer", 128.00);
  Bulk_quote bq("C++ Primer", 128.00, 2, 0.1);
  print_total(cout, q, 2);
  print_total(cout, bq, 2);
}
