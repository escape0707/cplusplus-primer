#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

// TODO: use iterator way to implement base_print
template <typename T>
void base_print(const vector<T> &vec, typename vector<T>::size_type idx) {
#ifndef NDEBUG
  std::cerr << "Size is " << vec.size() << endl;
#endif
  if (idx == vec.size()) {
    return;
  }
  cout << vec[idx] << ' ';
  base_print(vec, idx + 1);
}

template <typename T>
void print(const vector<T> &vec) {
  base_print(vec, 0);
  cout << endl;
}

int main() {
  vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  print(vec);
}