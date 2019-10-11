#include <list>
#include <map>
#include <vector>

using std::list;
using std::map;
using std::vector;

int main() {
  map<vector<int>::iterator, int> vec_it_map;
  map<list<int>::iterator, int> lst_it_map;
  // both can be declared

  list<int> ilst = {0, 1, 2, 3, 4};
  // but list<int>::iterator don't support operator< so we can't use lst_it_map
  // lst_it_map[ilst.begin()] = ilst.front();
}