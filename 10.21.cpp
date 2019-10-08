#include <iostream>

using std::cout, std::endl;

int main() {
  int i = 42;
  auto lambda = [&] {
    if (i == 0) {
      return true;
    } else {
      return --i == 0;
    }
  };
  while (!lambda()) {
    cout << i << ' ';
  }
  cout << endl;
}