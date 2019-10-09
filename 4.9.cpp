#include <iostream>

using std::cin, std::cout, std::endl;

int main() {
  const char *cp = "Hello World";
  if (cp && *cp) { // if cp is not nullptr and *cp is not '\0'
    cout << *cp << endl;
  }
}
