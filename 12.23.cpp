#include <cstring>
#include <iostream>
#include <string>

using std::cout, std::endl;
using std::strcat, std::strlen;
using std::string;

char *concat(const char *a, const char *b) {
  char *ret = new char[strlen(a) + strlen(b) + 1]();
  strcat(ret, a);
  strcat(ret, b);
  return ret;
}

char *concat(const string &a, const string &b) {
  char *ret = new char[a.length() + b.length() + 1]();
  strcat(ret, a.c_str());
  strcat(ret, b.c_str());
  return ret;
}

int main() {
  cout << concat("Hello, ", "world!") << endl;
  string a = "Hello, ", b = "world!";
  cout << concat(a, b) << endl;
}
