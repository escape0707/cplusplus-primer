#include <iostream>
#include "Sales_item.h"

int main() {
  Sales_item item;
  if (std::cin >> item) {
    int cnt = 1;
    Sales_item currItem;
    while (std::cin >> currItem) {
      if (currItem.isbn() == item.isbn()) {
        ++cnt;
      } else {
        std::cout << item.isbn() << '\t' << cnt << std::endl;
        item = currItem;
        cnt = 1;
      }
    }
    std::cout << item.isbn() << '\t' << cnt << std::endl;
  }
  return 0;
}