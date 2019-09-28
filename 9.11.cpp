#include <vector>

using std::vector;

vector<int> v1;                    // empty
vector<int> v2(10);                // ten ints of 0
vector<int> v3(10, 42);            // ten ints of 42
vector<int> v4 = {0, 1, 2, 3, 4};  // 5 ints of 0, 1, 2, 3, 4
vector<int> v5 = v2;               // same as v2, ten ints of 0
vector<int> v6 = v3;               // same as v3, ten ints of 42