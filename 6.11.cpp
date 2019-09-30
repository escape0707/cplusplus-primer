#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

void reset(int &i) {
  i = 0;
}

int main() {
  int val = 1;
  cout << val << endl;
  reset(val);
  cout << val << endl;


}
