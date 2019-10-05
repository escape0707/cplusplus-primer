#include <iostream>
#include <string>

using std::cout, std::endl;
using std::string;

int main() {
  string numbers("0123456789"), name("r2d2");
  cout << "result: " << numbers.find(name) << endl;
  cout << "npos:   " << string::npos << endl;
}