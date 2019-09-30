#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

void print(const int ia[10]) { // should be const int (&ia)[10]
  for (size_t i = 0; i != 10; ++i) {
    cout << ia[i] << endl;
  }
}

int main() {


}
