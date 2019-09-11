#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int ff(int a, int b = 0, int c = 0);
// error: default argument missing for parameter 2, 3
char *init(int ht = 24, int wd, char bckgrnd);
int main() {}
