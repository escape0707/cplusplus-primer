#include <iostream>
#include <string>
#include <vector>
#include "Sales_data.h"

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int main() {
  int x[10], *ip = x;
  cout << sizeof(bool) << ' ' << sizeof(char) << ' ' << sizeof(wchar_t) << ' '
       << sizeof(char16_t) << ' ' << sizeof(char32_t) << ' ' << sizeof(short)
       << ' ' << sizeof(int) << ' ' << sizeof(long) << ' ' << sizeof(long long)
       << ' ' << sizeof(float) << ' ' << sizeof(double) << ' '
       << sizeof(long double) << ' ' << sizeof(ip) << endl;
}
