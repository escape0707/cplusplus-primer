#include <iostream>
#include <string>
using std::cin, std::cout, std::endl;
using std::string;

int main() {
  string allStr, currStr;
  while (cin >> currStr) {
    allStr += currStr;
    allStr += ' '; //
  }
  cout << allStr << endl;
}