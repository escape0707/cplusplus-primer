#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>

class Sales_data;

// nonmember Sales_data interface functions
Sales_data add(const Sales_data &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);

class Sales_data {
  // friend declarations for nonmember Sales_data operations added
  friend Sales_data add(const Sales_data &, const Sales_data &);
  friend std::istream &read(std::istream &, Sales_data &);
  friend std::ostream &print(std::ostream &, const Sales_data &);

  // other members and access specifiers as before

 public:  // access specifier added
  // constructors added
  Sales_data() = default;
  Sales_data(const std::string &s) : bookNo(s) {}
  Sales_data(const std::string &s, unsigned n, double p)
      : bookNo(s), units_sold(n), revenue(p * n) {}
  // read will read a transaction from is into this object
  Sales_data(std::istream &is) { read(is, *this); }

  // new members: operations on Sales_data objects
  std::string isbn() const { return bookNo; }
  Sales_data &combine(const Sales_data &);

 private:  // access specifier added
  double avg_price() const;
  // data members are unchanged from 2.6.1
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

inline double Sales_data::avg_price() const {
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

// input transactions contain ISBN, number of copies sold, and sales price
std::istream &read(std::istream &is, Sales_data &item) {
  double price = 0;
  is >> item.bookNo >> item.units_sold >> price;
  item.revenue = price * item.units_sold;
  return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item) {
  os << item.isbn() << ' ' << item.units_sold << ' ' << item.revenue << ' '
     << item.avg_price();
  return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
  Sales_data sum = lhs;  // copy data memebers from lhs into sum
  sum.combine(rhs);      // add data memebers from rhs into sum
  return sum;
}

#endif
