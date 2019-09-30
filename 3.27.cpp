#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

constexpr unsigned txt_size() {
  return 42;
}

unsigned buf_size = 1024;
int a1[buf_size];
int a2[4 * 7 - 14];
int a3[txt_size()];
char st[11] = "fundamental";

int main() {

}
