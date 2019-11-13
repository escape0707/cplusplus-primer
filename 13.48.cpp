#include <vector>
#include <iostream>

#include "String.h"

using std::cerr, std::endl;
using std::vector;

int main() {
  vector<String> vs;
  int counter = 0;

  cerr << ++counter << endl;
  vs.push_back("Hello, ");
  cerr << ++counter << endl;
  vs.push_back("world!");

  cerr << ++counter << endl;
  vs.push_back("Hello, ");
  cerr << ++counter << endl;
  vs.push_back("world!");
  cerr << ++counter << endl;
  vs.push_back(" ...again!!");
  // so cold...
}
