#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int main() {
  int ival = -1, *ptr = &ival;
  vector<int> vec;

  cout << (ptr != 0 && *ptr++)
       << endl;  // if ptr is not nullptr then use the value dereferenced
                 // from ptr as bool result, and finally increase ptr

  cout << (ival++ && ival)
       << endl;  // if ival is not 0 then ++ival and test if ival is still not 0

  // cout << (vec[ival++] <= vec[ival]) << endl; // undefined
  cout << (vec[ival] <= vec[ival + 1]) << endl;
  ++ival;
}
