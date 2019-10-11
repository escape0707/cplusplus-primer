#include <algorithm>
#include <iterator>
#include <set>
#include <string>
#include <vector>

using std::back_inserter, std::inserter;
using std::copy;
using std::multiset;
using std::string;
using std::vector;

int main() {
  multiset<string> c;
  vector<string> v;
  // illegal, multiset<T> has no member of push_back
  // copy(v.begin(), v.end(), inserter(c, c.end()));
  // copy(v.begin(), v.end(), back_inserter(c));
  // legal
  copy(c.begin(), c.end(), inserter(v, v.end()));
  copy(c.begin(), c.end(), back_inserter(v));
}