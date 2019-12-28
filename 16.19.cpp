#include <iostream>
#include <vector>

using std::cout, std::endl;
using std::vector;

// template <typename C>
// void print(const C &c) {
//   for (const auto &elem : c) {
//     cout << elem << endl;
//   }
// }

template <typename C>
void print(const C &c) {
  typename C::size_type sz = c.size();
  for (typename C::size_type i = 0; i < sz; ++i) {
    cout << c[i] << endl;
  }
}

int main() {
  vector<int> ivec = {1, 3, 5, 7, 9};
  print(ivec);
}
