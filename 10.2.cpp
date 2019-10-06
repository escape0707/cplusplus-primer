#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <string>

using std::cin, std::cout, std::endl;
using std::copy, std::count;
using std::istream_iterator;
using std::list;
using std::string;

int main() {
  // cout << count(istream_iterator<string>(cin), istream_iterator<string>(),
  //               "Hello!")
  //      << endl;

  list<string> slist;
  copy(istream_iterator<string>(cin), istream_iterator<string>(),
       back_inserter(slist));

  cout << count(slist.cbegin(), slist.cend(), "Hello!") << endl;
}
