#include <ctime>
#include <iostream>
#include <random>

using std::cout, std::endl;
using std::default_random_engine, std::uniform_int_distribution;
using std::time;

static unsigned random_unsigned(int seed = time(nullptr)) {
  static uniform_int_distribution<unsigned> u;
  static default_random_engine e(seed);
  return u(e);
}

int main() {
  for (int i = 0; i < 20; ++i) {
    cout << random_unsigned(10) << ' ';
  }
}
