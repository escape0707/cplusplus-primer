#include <bitset>
#include <iostream>
#include <string>
#include <vector>

using std::bitset;
using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int main() {
  cout << (~'q' << 6) << endl;  // 11111111111111111110001110000000
  cout << bitset<8 * sizeof(~'q' << 6)>(~'q' << 6) << endl;
}
