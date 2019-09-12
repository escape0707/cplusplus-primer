#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

void f() {
  cout << 1 << endl;
};
void f(int) {
  cout << 2 << endl;
}
void f(int, int) {
  cout << 3 << endl;
}
void f(double, double = 3.14) {
  cout << 4 << endl;
}

int main() {
  // f(2.56, 42); // ambiguous: f(int, int), f(double, double = 3.14)
  f(42);
  f(42, 0);
  f(2.56, 3.14);
}
