// argument type: vector<int>

#include <map>
#include <string>
#include <utility>
#include <vector>

using std::map;
using std::pair;
using std::string;
using std::vector;

int main() {
  map<string, vector<int>> m;
  pair<string, vector<int>> p;
  pair<map<string, vector<int>>::iterator, bool> ret;
  ret = m.insert(p);
}