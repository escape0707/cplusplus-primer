#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using std::cbegin, std::cend;
using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int main(int argc, char **argv) {
  string result;
  for (char **sp = argv + 1; *sp; ++sp) {
    result += *sp;
  }
  cout << result << endl;


}
