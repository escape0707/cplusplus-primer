#include <deque>
#include <iostream>
#include <iterator>
#include <string>

using std::cin, std::cout, std::endl;
using std::deque;
using std::istream_iterator;
using std::string;

int main() {
  deque<string> text((istream_iterator<string>(cin)),
                     istream_iterator<string>());

  for (const string &word : text) {
    cout << word << endl;
  }
}