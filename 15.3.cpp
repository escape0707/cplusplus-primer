// see also Quote.h & Quote.cpp

#include <cstddef>
#include <ostream>

#include "Quote.h"

using std::ostream, std::endl;
using std::size_t;

__attribute__((unused)) static double print_total(ostream &os,
                                                  const Quote &item,
                                                  size_t n) {
  double ret = item.net_price(n);
  os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret
     << endl;
  return ret;
}
