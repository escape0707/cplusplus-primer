#include <cstddef>
#include <iostream>
#include <memory>
#include <vector>

#include "Basket.h"
#include "Bulk_quote.h"
#include "Quote.h"

using std::cout, std::endl;
using std::shared_ptr;
using std::size_t;
using std::vector;

int main() {
  Basket basket;
  Bulk_quote bq("0-201-54848-8", 50, 10, .25);
  Quote q("0-201-82470-1", 50);
  for (size_t i = 0; i < 15; ++i) {
    basket.add_item(bq);
    basket.add_item(q);
  }

  basket.total_receipt();
  // ISBN: 0-201-54848-8 # sold: 15 total due: 562.5
  // ISBN: 0-201-82470-1 # sold: 15 total due: 750
  // Total Sale: 1312.5
}
