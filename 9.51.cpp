// see also Date.h & Date.cpp

#include <iostream>
#include "Date.h"

using std::cout, std::endl;

int main() {
  cout << Date("January 1, 1900") << endl;
  cout << Date("1/1/1900") << endl;
  cout << Date("Jan 1, 1900") << endl;
}
