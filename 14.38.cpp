#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cout, std::endl;
using std::ifstream;
using std::stable_sort;
using std::string;
using std::vector;

using size_type = string::size_type;

class Fit {
 public:
  Fit(size_type lowerbound = 1, size_type upperbound = 10)
      : lowerbound(lowerbound), upperbound(upperbound) {}
  bool operator()(const string &s) {
    return lowerbound <= s.length() && s.length() <= upperbound;
  }

 private:
  string::size_type lowerbound, upperbound;
};

int main() {
  ifstream fin("a.in");
  Fit f;
  unsigned count = 0;
  for (string s; fin >> s;) {
    count += f(s);
  }
  cout << count << endl;
}
