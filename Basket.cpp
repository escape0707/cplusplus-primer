#include "Basket.h"

#include <cstddef>
#include <map>
#include <memory>
#include <ostream>
#include <utility>

#include "Quote.h"

using std::endl, std::ostream;
using std::map;
using std::shared_ptr;
using std::size_t;

void Basket::add_item(const shared_ptr<Quote> &p_sale) {
  ++items[p_sale];
}

void Basket::add_item(shared_ptr<Quote> &&p_sale) {
  ++items[std::move(p_sale)];
}

void Basket::add_item(const Quote &sale) {
  ++items[shared_ptr<Quote>(sale.clone())];
}

void Basket::add_item(Quote &&sale) {
  ++items[shared_ptr<Quote>(std::move(sale).clone())];
}

double Basket::total_receipt(ostream &os) const {
  double sum = 0.;
  for (map<shared_ptr<Quote>, size_t,
           bool (*)(const Quote &, const Quote &)>::const_iterator
           beg = items.cbegin(),
           end = items.cend();
       beg != end; ++beg) {
    sum += beg->first->print_total(beg->second, os);
    os << endl;
  }
  os << "Total Sale: " << sum << endl;
  return sum;
}

bool Basket::compare(const std::shared_ptr<Quote> &lhs,
                     const std::shared_ptr<Quote> &rhs) {
  return isbn_less(*lhs, *rhs);
}
