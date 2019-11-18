#include <algorithm>
#include <iostream>
#include <vector>

using std::cout, std::endl;
using std::replace_if;
using std::vector;

class test_equal {
 public:
  template <typename T>
  bool operator()(const T &t) {
    return t == value;
  }

 private:
  inline static int value = 2;
};

int main() {
  test_equal t;
  vector<int> vi = {0, 1, 2, 3, 3, 2, 1, 0};
  replace_if(vi.begin(), vi.end(), t, 42);
  for (const int &elem : vi) {
    cout << elem << ' ';
  }
  cout << endl;
}
