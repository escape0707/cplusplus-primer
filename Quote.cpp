#include <string>

#include "Quote.h"

using std::string;

Quote::Quote() = default;

Quote::Quote(const string &book, double sales_price)
    : bookNo(book), price(sales_price) {}

string Quote::isbn() const {
  return bookNo;
}

double Quote::net_price(std::size_t n) const {
  return n * price;
}

Quote::~Quote() = default;
