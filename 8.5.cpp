#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::getline;
using std::ifstream, std::ofstream;
using std::istream_iterator;
using std::string;
using std::vector;

vector<string> func(const string &ifile_name) {
  ifstream ifile(ifile_name);
  if (!ifile) {
    throw std::invalid_argument("Can't open input file.");
  }

  vector<string> svec((istream_iterator<string>(ifile)),
                      istream_iterator<string>());

  return svec;
}

int main() {
  for (const string &elem : func("8.1.cpp")) {
    cout << elem << '\n';
  }
  cout << endl;
}
