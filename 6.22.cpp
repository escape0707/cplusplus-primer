#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

void swap_pointer(int *&p1, int *&p2) {
  int *ptmp = p1;
  p1 = p2;
  p2 = ptmp;
}

int main() {
  int i = 0, j = 1;
  int *p1 = &i, *p2 = &j;

  cout << *p1 << ' ' << *p2 << endl;

  swap_pointer(p1, p2);

  cout << i << ' ' << j << endl;
  cout << *p1 << ' ' << *p2 << endl;


}
