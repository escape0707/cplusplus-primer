#include <cstddef>
#include <initializer_list>
#include <iostream>

using std::cout, std::endl;
using std::initializer_list;

template <typename T, size_t N>
void print(const T (&array)[N]) {
  for (const T &elem : array) {
    cout << elem << endl;
  }
}

int main() {
  int arr[] = {1, 3, 5, 7, 9};
  print(array);
}
