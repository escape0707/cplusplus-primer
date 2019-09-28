#include <list>
#include <vector>
#include <string>

using std::list;
using std::string;
using std::vector;

int main() {
  list<char *> cplist;
  vector<string> svec;

  svec.assign(cplist.cbegin(), cplist.cend());
}