#pragma once

#include <cstddef>
#include <string>

class Quote{
 public:
  Quote();
  Quote(const std::string &book, double sales_price);
  std::string isbn() const;
  virtual double net_price(std::size_t cnt) const;
  virtual ~Quote();

 private:
  std::string bookNo;

 protected:
  double price = 0.0;
};
