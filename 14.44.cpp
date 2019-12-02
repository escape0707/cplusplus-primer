#include <functional>
#include <iostream>
#include <map>

using std::cin, std::cout, std::endl;
using std::function;
using std::map;

int add(int i, int j) {
  return i + j;
}

auto mod = [](int i, int j) { return i % j; };

struct divide {
  int operator()(int denominator, int divisor) { return denominator / divisor; }
};

int main() {
  const map<char, function<int(int, int)>> binops = {
      {'+', add},
      {'-', std::minus<int>()},
      {'/', divide()},
      {'*', [](int i, int j) { return i * j; }},
      {'%', mod}};

  {
    int a, b;
    char op;
    while (cin >> a >> op >> b) {
      // throw std::out_of_range if the container does not have an element with
      // the specified key
      cout << binops.at(op)(a, b) << endl;
    }
  }
}
