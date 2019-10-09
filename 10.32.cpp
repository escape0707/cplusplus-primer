#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <utility>
#include <vector>

#include "Sales_item.h"

using std::accumulate;
using std::as_const;
using std::back_inserter, std::istream_iterator, std::ostream_iterator;
using std::cin, std::cout, std::endl;
using std::copy, std::find, std::sort;
using std::vector;

int main() {
  vector<Sales_item> records((istream_iterator<Sales_item>(cin)),
                             istream_iterator<Sales_item>());

  sort(records.begin(), records.end(), compareIsbn);

  for (vector<Sales_item>::const_iterator beg = records.cbegin(),
                                          end = records.cend();
       beg != end;) {
    vector<Sales_item>::const_iterator next =
        find_if(beg, end, [&lhs = *beg](const Sales_item &rhs) {
          return lhs.isbn() != rhs.isbn();
        });
    cout << accumulate(beg + 1, next, *beg) << endl;
    beg = next;
  }
}