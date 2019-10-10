// 256: 1024 as reserved
// 512: 1024 as reserved
// 1000: 2000 (it seems that when using resize(), g++ reallocate space by double of size(), rather
// than capacity()?)
// 1048: 2048 (reallocated during push_back())

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using std::copy;
using std::cout, std::endl;
using std::ifstream;
using std::istream_iterator, std::back_inserter;
using std::string;
using std::vector;

ifstream fin("a.in");

template <typename C>
void print_info(const C &c) {
  cout << "C size: " << c.size() << "\tcapacity: " << c.capacity()
       << endl;
}

int main() {
  vector<string> svec;
  svec.reserve(1024);
  copy(istream_iterator<string>(fin), istream_iterator<string>(),
       back_inserter(svec));
  svec.resize(svec.size() + svec.size() / 2);
  print_info(svec);
}