#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include "Sales_data.h"

using std::cin, std::cout, std::endl;
using std::copy, std::sort;
using std::ostream_iterator;
using std::string;
using std::vector;

bool compareIsbn(const Sales_data &book1, const Sales_data &book2) {
  return book1.isbn() < book2.isbn();
}

int main() {
  Sales_data d1("CppPrimer"), d2("JavaCore"), d3("PythonCookBook"),
      d4("CppCore"), d5("AwesomeCPP");
  vector<Sales_data> data_vec{d1, d2, d3, d4, d5};

  sort(data_vec.begin(), data_vec.end(), compareIsbn);
  copy(data_vec.cbegin(), data_vec.cend(),
       ostream_iterator<Sales_data>(cout, "\n"));
}
