#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

string text[10] = {"H", "e", "l", "l", "o", "W", "o", "r", "l", "d"};

string (&func())[10] {
  return text;
}

int main() {
  for (const string &elem : func()) {
    cout << elem;
  }
  cout << endl;
}
