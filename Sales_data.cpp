#include "Sales_data.h"

Sales_data() = default;

Sales_data(const std::string &s, unsigned n, double p)
    : bookNo(s), units_sold(n), revenue(p * n) {}

explicit Sales_data(const std::string &s) : bookNo(s) {}

explicit Sales_data(std::istream &is) {
  is >> *this;
}

std::string isbn() const {
  return bookNo;
}

Sales_data &operator+=(const Sales_data &rhs);

inline double Sales_data::avg_price() const {
  if (units_sold) {
    return revenue / units_sold;
  } else {
    return 0;
  }
}

Sales_data &Sales_data::operator+=(const Sales_data &rhs) {
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
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
