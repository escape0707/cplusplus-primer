#include <vector>

using std::vector;

bool find(vector<int>::const_iterator begin,
             const vector<int>::const_iterator &end,
             const int &val) {
  for (; begin != end; ++begin) {
    if (*begin == val) {
      return true;
    }
  }
  return false;
}