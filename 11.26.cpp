#include <map>
#include <string>

using std::map;
using std::string;

int main() {
  map<int, string> m;
  m[0] = "1";

  int a;
  double b;
  m[a] = "2";
  m[b] = "3";

  string s = m[b];
}
