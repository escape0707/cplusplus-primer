#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

typedef string Type;
Type initVal();  // return string

class Exercise {
 public:
  typedef double Type;
  Type setVal(Type);             // return double, parm double
  Type initVal() { return .0; }  // return double

 private:
  int val;
};

// return string, parm double, no declaration matches
// Type Exercise::setVal(Type parm) {
Exercise::Type Exercise::setVal(Type parm) {
  // initVal refers to in-class member function
  val = parm + initVal();
  return val;
}

int main() {}
