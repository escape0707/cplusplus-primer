#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using std::cin, std::cout, std::endl;
using std::copy;
using std::getline;
using std::ifstream;
using std::istream_iterator, std::ostream_iterator;
using std::istringstream;
using std::string;
using std::vector;

int main() {
  // store each line from a file in a vector<string>
  ifstream fin("a.in");
  vector<string> text;

  for (string line; getline(fin, line);) {
    text.push_back(std::move(line));
  }

  // use an istringstream to read each element of the vector a word at a time
  for (const string &elem : text) {
    istringstream iss(elem);
    copy(istream_iterator<string>(iss), istream_iterator<string>(),
         ostream_iterator<string>(cout));
    cout << endl;
  }
}
