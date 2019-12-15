#pragma once

#include <cstddef>
#include <iostream>
#include <map>
#include <memory>

#include "Quote.h"

class Basket {
 public:
  void add_item(const std::shared_ptr<Quote> &p_sale);
  void add_item(std::shared_ptr<Quote> &&p_sale);
  void add_item(const Quote &sale);
  void add_item(Quote &&sale);
  double total_receipt(std::ostream &os = std::cout) const;

 private:
  static bool compare(const std::shared_ptr<Quote> &lhs,
                      const std::shared_ptr<Quote> &rhs);

  std::map<std::shared_ptr<Quote>,
           size_t,
           bool (*)(const std::shared_ptr<Quote> &lhs,
                    const std::shared_ptr<Quote> &rhs)>
      items{compare};
};
