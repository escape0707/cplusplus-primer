#include <iostream>
#include <string>
#include <vector>

#include "14.35.cpp"

using std::cout, std::endl;
using std::string;
using std::vector;

int main() {
  ReadString scanner;
  vector<string> vs;
  while (cin) {
    vs.push_back(scanner());
  }
  for (const string &elem : vs) {
    cout << elem << endl;
  }
}
