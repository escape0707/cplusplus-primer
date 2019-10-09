#include <algorithm>
#include <iterator>
#include <iostream>
#include <functional>
#include <string>
#include <vector>

using namespace std::placeholders;

using std::bind, std::copy, std::find_if_not;
using std::cout, std::endl;
using std::ostream_iterator;
using std::string;
using std::vector;

// return whether the length of s is greater than sz
bool check_size(const string &s, const string::size_type &sz) {
  return s.length() >= sz;
}

int main() {
  // a vector of ints
  vector<int> ivec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  // specified string
  string s{"Hello"};

  // find the first element in ivec that has a value greater than the length of
  // s
  vector<int>::const_iterator pos =
      find_if_not(ivec.cbegin(), ivec.cend(), bind(check_size, s, _1));

  copy(pos, ivec.cend(), ostream_iterator<int>(cout, " "));
  cout << endl;
}
