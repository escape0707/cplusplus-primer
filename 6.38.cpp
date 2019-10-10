#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};
// returns a reference to an array of five int elements
decltype(odd) &arrPtr(int i) {
  return i % 2 ? odd : even;  // returns a reference to the array
}

int main() {
  for (const int &elem : arrPtr(0)) {
    cout << elem << ' ';
  }
  cout << endl;

  for (const int &elem : arrPtr(1)) {
    cout << elem << ' ';
  }
  cout << endl;
}
