#include <iostream>
#include <string>

#include "Quote.h"

using std::cout;
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

void Quote::debug() const {
  cout << "bookNo: " << bookNo << ", price: " << price;
}

Quote::~Quote() = default;
