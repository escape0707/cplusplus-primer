#include <iostream>

using std::cout, std::endl;

class judge {
 public:
  int operator()(int value, int a, int b) {
    if (value > 0) {
      return a;
    }
    return b;
  }
};

int main() {
  judge j;
  cout << j(42, 1, -2) << endl;
}
