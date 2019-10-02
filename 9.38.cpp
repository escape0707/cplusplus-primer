#include <iostream>
#include <vector>

using std::cout, std::endl;
using std::vector;

void print_info(const vector<int> &ivec) {
  cout << "ivec: size: " << ivec.size() << " capacity: " << ivec.capacity()
       << endl;
}

int main() {
  vector<int> ivec;
  print_info(ivec);

  for (vector<int>::size_type ix = 0; ix != 24; ++ix) {
    ivec.push_back(ix);
  }
  print_info(ivec);

  ivec.reserve(50);
  print_info(ivec);

  while(ivec.size()!=ivec.capacity()) {
    ivec.push_back(0);
  }
  print_info(ivec);

  ivec.push_back(42);
  print_info(ivec);

  ivec.shrink_to_fit();
  print_info(ivec);
}