#pragma once

#include <iostream>
#include <string>

class Sales_data {
  friend Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);
  friend std::ostream &operator<<(std::ostream &os, const Sales_data &rhs);
  friend std::istream &operator>>(std::istream &is, Sales_data &rhs);

 public:
  Sales_data();
  Sales_data(const std::string &s, unsigned n, double p);
  explicit Sales_data(const std::string &s);
  explicit Sales_data(std::istream &is);
  Sales_data &operator=(const std::string &s);
  std::string isbn() const;
  Sales_data &operator+=(const Sales_data &rhs);

 private:
  double avg_price() const;
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};
