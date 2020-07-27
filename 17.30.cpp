#include <ctime>
#include <iostream>
#include <limits>
#include <random>

using std::cout, std::endl;
using std::default_random_engine, std::uniform_int_distribution;
using std::numeric_limits;
using std::time;

static unsigned random_unsigned(unsigned a = 0,
                                unsigned b = numeric_limits<unsigned>::max()) {
  static uniform_int_distribution<unsigned> u(a, b);
  static default_random_engine e(time(nullptr));
  return u(e);
}

int main() {
  for (int i = 0; i < 20; ++i) {
    cout << random_unsigned(0, 9) << ' ';
  }
}
