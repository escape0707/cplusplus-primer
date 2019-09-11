#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int calc(int, int);
int calc(const int, const int);

// only return type has difference, ambiguous
int get();
double get();

int *reset(int *);
double *reset(double *);

int main() {
}
