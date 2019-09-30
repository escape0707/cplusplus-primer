#include <list>
#include <iostream>
#include <iterator>
#include <string>

using std::cin, std::cout, std::endl;
using std::list;
using std::istream_iterator;
using std::string;

int main() {
  list<string> text((istream_iterator<string>(cin)),
                     istream_iterator<string>());

  for (const string &word : text) {
    cout << word << endl;
  }
}
