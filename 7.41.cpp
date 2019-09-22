#include "Sales_data.h"

using std::cout, std::endl;

int main() {
  Sales_data a;
  cout << endl;
  Sales_data b("b");
  cout << endl;
  Sales_data c("c", 1, 2);
  cout << endl;
  Sales_data d(std::cin);
  cout << endl;
}