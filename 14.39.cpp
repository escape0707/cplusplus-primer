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
  Fit f1(1, 9), f2(10, -1);
  unsigned count1 = 0, count2 = 0;
  for (string s; fin >> s;) {
    count1 += f1(s);
    count2 += f2(s);
  }
  cout << count1 << endl;
  cout << count2 << endl;
}
