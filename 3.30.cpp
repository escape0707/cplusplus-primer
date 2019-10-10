#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int main() {
  constexpr size_t array_size = 10;
  int ia[array_size];
  // for (size_t ix = 1; ix <= array_size; ++ix) {  // error
  for (size_t ix = 0; ix < array_size; ++ix) {
    ia[ix] = ix;
    // ia[ix - 1] = ix;  // or change to this
  }
  for (const int &i : ia) {
    cout << i << ' ';
  }
  cout << endl;
}
