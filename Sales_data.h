#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>

struct Sales_data {
  // new members: operations on Sales_data objects
  std::string isbn() const { return bookNo; }
  Sales_data &combine(const Sales_data &);
  double avg_price() const;

  // data members are unchanged from 2.6.1
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};
// nonmember Sales_data interface functions
Sales_data add(const Sales_data &, const Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);

double Sales_data::avg_price() const {
  if (units_sold) {
    return revenue / units_sold;
  } else {
    return 0;
  }
}

Sales_data &Sales_data::combine(const Sales_data &rhs) {
  units_sold += rhs.units_sold;  // add the memebers of rhs into
  revenue += rhs.revenue;        // the members of "this" object
  return *this;  // return the object on which the function was called
}

#endif
