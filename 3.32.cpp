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

  int arr2[array_size];
  for (size_t i = 0; i < array_size; ++i) {
    arr2[i] = arr[i];
  }

    for (const int &i : arr2) {
      cout << i << ' ';
    }
  cout << endl;

  vector<int> ivec(10);
  for (size_t i = 0; i < ivec.size(); ++i) {
    ivec[i] = i;
  }
  for (const auto &i: ivec) {
    cout << i << ' ';
  }
  cout << endl;

  return 0;
}
