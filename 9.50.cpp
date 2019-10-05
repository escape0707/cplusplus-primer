#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::stoi, std::stod;
using std::string;
using std::vector;

int main() {
  vector<string> ivec{"0", "1", "2", "3", "4"};

  int isum = 0;
  for (const string &str : ivec) {
    isum += stoi(str);
  }
  cout << isum << endl;

  vector<string> dvec{".0", ".1", ".2", ".3", ".4"};
  double dsum = .0;
  for (const string &str : dvec) {
    dsum += stod(str);
  }
  cout << dsum << endl;
}
