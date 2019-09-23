#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::cerr, std::endl;
using std::string;
using std::vector;

class Debug {
 public:
  constexpr Debug(bool b = true) : hw(b), io(b), other(b) {}
  constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) {}
  constexpr bool any() const { return hw || io || other; }
  constexpr void set_io(bool b) { io = b; }
  constexpr void set_hw(bool b) { hw = b; }
  constexpr void set_other(bool b) { hw = b; }

 private:
  bool hw;     // hardware errors other than IO errors
  bool io;     // IO errors
  bool other;  // other errors
};

int main() {
  constexpr Debug io_sub(false, true, false);  // debugging IO
  if (io_sub.any()) {                          // equivalent to if(true)
    cerr << "print appropriate error messages" << endl;
  }

  constexpr Debug prod(false);  // no debugging during production
  if (prod.any()) {             // equivalent to if (false)
    cerr << "print an error message" << endl;
  }
}
