#include "Quote.h"

#include <iostream>
#include <string>
#include <utility>

using std::cout, std::ostream;
using std::string;

Quote::Quote() = default;

Quote::Quote(const string &book, double sales_price)
    : bookNo(book), price(sales_price) {}

Quote::Quote(const Quote &other) = default;

Quote::Quote(Quote &&other) = default;

Quote &Quote::operator=(const Quote &other) = default;

Quote &Quote::operator=(Quote &&other) = default;

Quote::~Quote() = default;

string Quote::isbn() const {
  return bookNo;
}

double Quote::net_price(std::size_t n) const {
  return n * price;
}

void Quote::debug() const {
  cout << "bookNo: " << bookNo << ", price: " << price;
}

double Quote::print_total(size_t n, ostream &os) const {
  double ret = net_price(n);
  os << "ISBN: " << bookNo << " # sold: " << n << " total due: " << ret;
  return ret;
}

Quote *Quote::clone() const & {
  return new Quote(*this);
}

Quote *Quote::clone() && {
  return new Quote(std::move(*this));
}

bool isbn_less(const Quote &lhs, const Quote &rhs) {
  return lhs.bookNo < rhs.bookNo;
}
