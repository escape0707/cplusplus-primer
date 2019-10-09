#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int i;
double d;

void print() {
  cout << i << ' ' << d << endl;
}

int main() {
  d = i = 3.5;
  print();  // 3 3

  i = d = 3.5;
  print();  // 3 3.5
}
