#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

char *init(int ht, int wd = 80, char bckgrnd = ' ');

int main() {
  init();
  init(24, 10);
  init(14, '*');  // warning: equals init(14, static_cast<int>('*'), ' ');
}
