#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

template <typename T, size_t N>
void print(const T (&arr)[N]) {
  cout << N << ": ";
  for (const T &element : arr) {
    cout << element << ", ";
  }
  cout << endl;
}

string sa[10];
int ia[10];
int main() {
  string sa2[10];
  int ia2[10];

  print(sa);
  print(ia);
  print(sa2);
  print(ia2);
}
