#include <iostream>
#include <string>

using std::cout, std::endl, std::ostream;
using std::string;

class base {
 public:
  string name() { return basename; }
  virtual void print(ostream &os) { os << basename; }  // trival print

 private:
  string basename = "base";
};

class derived : public base {
 public:
  void print(ostream &os) {
    // print(os);  // calls derived::print and recurse infinitely
    base::print(os);
    os << ' ' << i;
  }

 private:
  int i = 42;
};

int main() {
  base().print(cout);
  cout << endl;
  derived().print(cout);
  cout << endl;
}
