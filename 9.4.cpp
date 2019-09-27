#include <vector>

using std::vector;

bool include(vector<int>::const_iterator begin,
             const vector<int>::const_iterator &end,
             const int &val) {
  while (begin != end && *begin++ != val)
    ;
  return (begin != end && *begin == val);
}