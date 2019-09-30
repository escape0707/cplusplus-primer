#include <iostream>
#include "Sales_item.h"

int main() {
  Sales_item book;
  if (std::cin >> book) {
    Sales_item currTrans;
    while (std::cin >> currTrans) {
      book += currTrans;
    }
    std::cout << book << std::endl;
  }
}