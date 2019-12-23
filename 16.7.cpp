#include <cstddef>
#include <iostream>

using std::cout, std::endl;
using std::size_t;

template <typename T, size_t N>
constexpr size_t size(const T (&)[N]) {
  return N;
}

int main() {
  int arr[] = {1, 3, 5, 7, 9};
  cout << size(arr) << endl;
}
