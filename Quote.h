#pragma once

#include <cstddef>
#include <iostream>
#include <string>

class Quote {
  friend bool isbn_less(const Quote &lhs, const Quote &rhs);

 public:
  Quote();
  Quote(const std::string &book, double sales_price);
  Quote(const Quote &other);
  Quote(Quote &&other);
  Quote &operator=(const Quote &other);
  Quote &operator=(Quote &&other);
  virtual ~Quote();
  std::string isbn() const;
  virtual double net_price(std::size_t cnt) const;
  virtual void debug() const;
  double print_total(std::size_t n, std::ostream &os = std::cout) const;
  virtual Quote *clone() const &;
  virtual Quote *clone() &&;

 private:
  std::string bookNo;

 protected:
  double price = 0.0;
};

bool isbn_less(const Quote &lhs, const Quote &rhs);
