#include <iostream>
#include <string>
#include <utility>

using std::cerr, std::endl;
using std::string;

void f(string &&s) {
  cerr << "f(string &&s)" << endl;
}

void f(string s) {
  cerr << "f(string s)" << endl;
}

int main() {
  string s("Hello");
  f(s);
  // f(std::move(s));  // ambiguous
}
