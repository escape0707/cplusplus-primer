#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using std::back_inserter, std::istream_iterator, std::ostream_iterator;
using std::cin, std::cout, std::endl;
using std::copy;
using std::vector;

vector<int> *factory() {
  return new vector<int>();
}

template <typename Container>
void read(Container &c) {
  using T = typename Container::value_type;
  copy(istream_iterator<T>(cin), istream_iterator<T>(), back_inserter(c));
}

template <typename Container>
void print(const Container &c) {
  using T = typename Container::value_type;
  copy(c.cbegin(), c.cend(), ostream_iterator<T>(cout, " "));
}

int main() {
  vector<int> *pv = factory();
  read(*pv);
  print(*pv);
  cout << endl;
  delete pv;
}