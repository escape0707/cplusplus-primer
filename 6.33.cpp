#include <iostream>
#include <string>
#include <utility>
#include <vector>

using std::cout, std::endl, std::ostream;
using std::string;
using std::vector;

template <typename RandomIt>
ostream &print(ostream &os, RandomIt &&first, const RandomIt &second) {
  if (first >= second) {
    return os;
  }
  os << *first;
  if (++first < second) {
    os << ' ';
  }
  return print(os, std::move(first), second);
}

template <typename RandomIt>
ostream &print(ostream &os, const RandomIt &first, const RandomIt &second) {
  RandomIt f = first;
  return print(os, std::move(f), second);
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  return print(os, vec.cbegin(), vec.cend());
}

int main() {
  vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  cout << vec << endl;
}
