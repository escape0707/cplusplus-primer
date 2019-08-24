#include <iostream>
#include <string>

using std::cin, std::cout, std::endl;
using std::string;

int main() {
  string str = "Hello, world!";

  for (char &c : str) {
    c = 'X';
  }

  string::size_type index = 0;
  while (index != str.length()) {
    str[index++] = 'X';
  }

  for (index = 0; index != str.length(); ++index) {
    str[index] = 'X';
  }

  cout << str << endl;

  return 0;
}
