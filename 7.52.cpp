#include <iostream>
#include <string>

using std::cout, std::endl;
using std::string;

struct Sales_data {
  string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

// compiles even with in-class initializers ?!
Sales_data item = {"978-0590353403", 25, 15.99};

int main() {
  cout << item.bookNo << ' ' << item.units_sold << ' ' << item.revenue << endl;
}