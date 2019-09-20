#include <iostream>
#include <string>
#include <vector>
#include "Screen.h"

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int main() {
  Screen myScreen(5, 5, 'X');
  myScreen.move(4, 0).set('#').display(cout);
  cout << '\n';
  myScreen.display(cout);
  cout << '\n';
}
