#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int main() {
  constexpr int array_size = 10;
  int arr[array_size];
  for (size_t i = 0; i < array_size; ++i) {
    arr[i] = i;
  }

  for (const int &i : arr) {
    cout << i << ' ';
  }
  cout << endl;


}
