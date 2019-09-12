#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int calc1(int &, int &);
int calc1(const int &, const int &); // top-level const

int calc2(char *, char *);
int calc2(const char *, const char *); // low-level const

int calc3(char *, char *);
int calc3(char *const, char *const); // top-level const

int main() {
}
