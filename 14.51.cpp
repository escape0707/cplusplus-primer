#include <iostream>

using std::cout, std::endl;

struct LongDouble {
  LongDouble(double = 0.0);
  operator double();
  operator float();
};

static void calc(int) {
  cout << "static void calc(int)" << endl;
}

static void calc(LongDouble) {
  cout << "static void calc(LongDouble)" << endl;
}

int main() {
  double dval = 0;
  calc(dval);  // calc(int), A standard conversion sequence is always better
               // than a user-defined conversion sequence...
  // see:
  // https://en.cppreference.com/w/cpp/language/overload_resolution#Ranking_of_implicit_conversion_sequencesRanking_of_implicit_conversion_sequences
}
