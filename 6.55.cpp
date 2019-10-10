#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int func(int, int) {
  return 42;
}

int add(int a, int b) {
  return a + b;
}

int subtract(int a, int b) {
  return a - b;
}

int multiply(int a, int b) {
  return a * b;
}

int divide(int a, int b) {
  return a / b;
}

vector<int (*)(int, int)> fpvec = {add, subtract, multiply, divide};

int main() {
  for (int (*const &elem)(int, int) : fpvec) {
    cout << elem(42, 10) << ' ';
  }
  cout << endl;
}
