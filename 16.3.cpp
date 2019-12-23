#include <functional>
#include <iostream>

#include "Sales_data.h"

using std::cout, std::endl;
using std::less;

template <typename T>
int compare(const T &v1, const T &v2) {
  if (less<T>()(v1, v2))
    return -1;
  if (less<T>()(v2, v1))
    return 1;
  return 0;
}

int main() {
  Sales_data data1("book1"), data2("book2");
  cout << compare(data1, data2) << endl;
}
