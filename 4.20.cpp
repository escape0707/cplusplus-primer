#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int main() {
  vector<string>::iterator iter;
  *iter++;
  (*iter)++;
  *iter.empty();
  iter->empty();
  ++*iter;
  iter++->empty();

  return 0;
}
