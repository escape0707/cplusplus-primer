// see also Quote.h & Quote.cpp, Bulk_quote.h & Bulk_quote.cpp

#include <iostream>

#include "Bulk_quote.h"
#include "Quote.h"

using std::cout, std::endl;

int main() {
  Quote q("C++ Primer", 128);
  Bulk_quote bq("C++ Primer", 128, 2, 0.1);
  q.debug();
  cout << endl;
  bq.debug();
  cout << endl;
  Quote &rq = bq;
  Bulk_quote &rbq /*?*/ = bq;
  rq.debug();
  cout << endl;
  rbq.debug();
  cout << endl;
}
