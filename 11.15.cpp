#include <map>
#include <vector>

using std::map;
using std::vector;

map<int, vector<int>>::mapped_type ivec;  // vector<int>
map<int, vector<int>>::key_type i;        // int
map<int, vector<int>>::value_type p;      // pair<const int, vector<int>>