#include <iostream>
#include <string>

#include "Sales_data.h"

using std::istream, std::ostream;
using std::string;

Sales_data::Sales_data() = default;

Sales_data::Sales_data(const std::string &s, unsigned n, double p)
    : bookNo(s), units_sold(n), revenue(p * n) {}

Sales_data::Sales_data(const std::string &s) : bookNo(s) {}

Sales_data::Sales_data(std::istream &is) {
  is >> *this;
}

std::string Sales_data::isbn() const {
  return bookNo;
}

Sales_data &Sales_data::operator+=(const Sales_data &rhs) {
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}


double Sales_data::avg_price() const {
  if (units_sold) {
    return revenue / units_sold;
  } else {
    return 0;
  }
}

std::istream &operator>>(std::istream &is, Sales_data &item) {
  double price = 0;
  is >> item.bookNo >> item.units_sold >> price;
  item.revenue = price * item.units_sold;
  return is;
}

std::ostream &operator<<(std::ostream &os, const Sales_data &item) {
  os << item.isbn() << ' ' << item.units_sold << ' ' << item.revenue << ' '
     << item.avg_price();
  return os;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
  Sales_data sum = lhs;
  sum += rhs;
  return sum;
}
