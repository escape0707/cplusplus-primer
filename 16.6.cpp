#include <cstddef>
#include <iostream>

using std::cout, std::endl;
using std::size_t;

template <typename T, size_t N>
T *begin(T (&array)[N]) {
  return array;
}

template <typename T, size_t N>
T *end(T (&array)[N]) {
  return array + N;
}

int main() {
  int arr[3] = {1, 2, 3};
  cout << *begin(arr) << endl;
  cout << *(end(arr) - 1) << endl;
}
