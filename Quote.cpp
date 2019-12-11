#include "Quote.h"

#include <iostream>
#include <string>

using std::cout;
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
