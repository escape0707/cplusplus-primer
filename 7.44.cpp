#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

class NoDefault {
 public:
  NoDefault(const int &i) { cout << i; }
  // additional members follow, but no other constructors
};

// error: no matching function for call to ‘NoDefault::NoDefault()’
// vector<NoDefault> vec(10);

int main() {}
