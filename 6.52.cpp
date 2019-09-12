#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

void manip(int, int);
double dobj;

int main() {
  manip('a', 'z');    // rank 4, arithmetic conversion
  manip(55.4, dobj);  // rank 4, arithmetic conversion
}
