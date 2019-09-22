// no because no single argument constructors defined
// see Person.h

#include "Person.h"

using std::cout, std::endl;

int main() {
  Person a("Alice");
  print(cout, a);
  cout << endl;
  print(cout, "Bob");
  cout << endl;
}