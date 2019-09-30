#include <iostream>
#include <vector>

using std::cout, std::endl;
using std::vector;

int main() {
  vector<int> ivec;

  cout << ivec.at(0) << ' ';      // exception 'std::out_of_range'
  cout << ivec[0] << ' ';         // Segmentation fault
  cout << ivec.front() << ' ';    // Segmentation fault
  cout << *ivec.begin() << endl;  // Segmentation fault
}