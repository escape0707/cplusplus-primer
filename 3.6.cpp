#include <iostream>
#include <string>

using std::cin, std::cout, std::endl;
using std::string;

int main() {
  string str = "Hello, world!";

  for (auto &c : str) {
    c = 'X';
  }

  cout << str << endl;


}