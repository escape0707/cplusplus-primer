#include <iostream>
#include <map>
#include <utility>

using std::cout, std::endl;
using std::map;
using std::pair;

int main() {
  map<int, int> m = {{42, 0}};
  map<int, int>::iterator it = m.begin();
  it->second = 42;
  for (const pair<const int, int> &p : m) {
    cout << p.first << ": " << p.second << endl;
  }
}