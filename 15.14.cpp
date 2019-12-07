#include <iostream>
#include <string>

using std::cout, std::endl, std::ostream;
using std::string;

class base {
 public:
  string name() { return basename; }
  virtual void print(ostream &os = cout) { os << basename; }  // trival print

 private:
  string basename = "base";
};

class derived : public base {
 public:
  void print(ostream &os = cout) override{
    // print(os);  // calls derived::print and recurse infinitely
    base::print(os);
    os << ' ' << i;
  }

 private:
  int i = 42;
};

int main() {
  base bobj;
  base *bp1 = &bobj;
  base &br1 = bobj;
  derived dobj;
  base *bp2 = &dobj;
  base &br2 = dobj;
  bobj.print();  // base::print
  cout << endl;
  dobj.print();  // derived::print
  cout << endl;
  bp1->name();  // base::name
  bp2->name();  // base::name
  br1.print();  // base::print
  cout << endl;
  br2.print();  // derived::print
  cout << endl;
}
