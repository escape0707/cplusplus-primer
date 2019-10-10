#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int main() {
  vector<int> ivec(10);
  vector<int>::size_type cnt = ivec.size();
  // assign values from size...1 to the elements in ivec
  for (vector<int>::size_type ix = 0; ix != ivec.size(); ++ix, --cnt) {
    ivec[ix] = cnt;
  }

  for (const int &i : ivec) {
    cout << i << ' ';
  }
  cout << endl;

  cnt = ivec.size();
  for (vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--) {
    ivec[ix] = cnt;
  }

  for (const int &i : ivec) {
    cout << i << ' ';
  }
  cout << endl;
}
