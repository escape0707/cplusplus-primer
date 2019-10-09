#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int main() {
  int i;
  double d;
  const string *ps;
  char *pc;
  void *pv;

  pv = const_cast<string *>(ps);
  i = static_cast<int>(*pc);
  pv = static_cast<void *>(&d);
  pc = static_cast<char *>(pv);
}
