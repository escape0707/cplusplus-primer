// We add a using statement in Stack and try to alias a not exist type member
// in T. So that when Stack<T> is instantiated, compiler can't find this not
// exist type anywhere and give us an error to indicate that Stack<T> is
// instantiated.

#include <string>

template <typename T>
class Stack {
  typedef typename T::ThisDoesNotExist
      StaticAssert;  // T::NotExisting doesn't exist at all!
};

void f1(Stack<char>);  // No instantiation

class Exercise {
  Stack<double> &rsd;  // No instantiation, references don't need instantiation,
                       // are similar to pointers in this
  Stack<int> si;       // Instantiate Stack<int>
};

int main() {
  Stack<char> *sc;  // No Instantiation, a pointer doesn't need instantiation
  f1(*sc);          // Instantiate Stack<char>
  int iObj = sizeof(Stack<std::string>);  // Instantiate Stack<std::string>
}
