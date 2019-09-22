#include <iostream>
#include <string>
#include <vector>
#include "Sales_data.h"

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

class NoDefault {
 public:
  NoDefault(const int &i) { cout << i; }
  // additional members follow, but no other constructors
};

struct C {
  C() : c_member(NoDefault(42)) {}
  NoDefault c_member;
};

vector<C> vec(10); // ok

int main() {
}
