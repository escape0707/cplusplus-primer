// similar to std::string.

#include <cstddef>
#include <cstring>
#include <iostream>

using std::cin, std::cout, std::endl, std::ostream;
using std::size_t;
using std::strcpy;

class str {
 public:
  void push_back(const char c) {
    check_capacity(len + 1);
    ptr[len++] = c;
  }
  ostream &print(ostream &os) {
    os << ptr;
    return os;
  }

 private:
  size_t len = 0;
  size_t capacity = 0;
  char *ptr = new char[1]();
  void check_capacity(const size_t size) {
    if (size > capacity) {
      char *s = new char[size > 2 * capacity ? size : 2 * capacity]();
      strcpy(s, ptr);
      delete[] ptr;
      ptr = s;
    }
  }
};

int main() {
  str s;
  for (char c; cin.get(c);) {
    s.push_back(c);
  }
  s.print(cout);
}
