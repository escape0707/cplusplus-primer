#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::istream;
using std::string;
using std::vector;

istream &process_input(istream &is) {
  string buf;
  while (cin >> buf) {
    cout << buf;
  }
  return is;
}

int main() {
  int i;
  cin >> i;
  process_input(cin);
  if (cin) {
    cout << i << endl;
  }
}
