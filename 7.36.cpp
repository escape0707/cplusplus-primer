#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

struct X {
  X (int i, int j) : base(i), rem(i % j) {}
  int rem, base;
};

int main() {
}
