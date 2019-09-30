#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::istream_iterator;
using std::string;
using std::vector;

int main() {
  vector<string> v(istream_iterator<string>(cin), istream_iterator<string>());
}
