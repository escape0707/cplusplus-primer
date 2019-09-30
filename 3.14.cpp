#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::istream_iterator;
using std::string;
using std::vector;

int main() {
  vector<int> v((istream_iterator<int>(cin)), istream_iterator<int>());
}
