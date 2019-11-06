#include "Sales_data.h"

bool fcn(const Sales_data *trans, Sales_data accum) {
  Sales_data item1(*trans), item2(accum);
  return item1.isbn() != item2.isbn();
} // three in total: item1, item2, accum
