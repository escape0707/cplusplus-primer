#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

// return the plural version of word if ctr is greater than 1
string make_plural(size_t ctr, const string &word, const string &ending = "s") {
  return ctr > 1 ? word + ending : word;
}

int main() {
  cout << make_plural(10, "success") << ' ' << make_plural(10, "failure") << endl;
}
