#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int max(int i, int *ip) {
  return (i > *ip) ? i : *ip;
}

int main() {
  int i = 1, j = 2;
  int *ip = &j;

  cout << max(i, ip) << endl;


}
