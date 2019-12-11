#pragma once

#include <cstddef>
#include <string>

class Quote {
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

 private:
  std::string bookNo;

 protected:
  double price = 0.0;
};
