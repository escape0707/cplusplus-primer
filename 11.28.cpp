#include <map>
#include <string>
#include <vector>

using std::map;
using std::string;
using std::vector;

int main() {
  map<string, vector<int>> m;
  map<string, vector<int>>::iterator ret = m.find("Hello");
}