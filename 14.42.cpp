#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using std::bind, std::greater, std::multiplies, std::not_equal_to;
using std::count_if;
using std::cout, std::endl;
using std::find_if_not;
using std::string;
using std::transform;
using std::vector;
using std::placeholders::_1;

int main() {
  vector<int> vi = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096};
  cout << count_if(vi.cbegin(), vi.cend(), bind(greater<int>(), _1, 1024))
       << endl;

  vector<string> vs = {"foo", "fooh", "pooh", "pool"};
  *find_if_not(vs.begin(), vs.end(), bind(not_equal_to(), _1, "pooh")) = "ooh!";
  for (const string &elem : vs) {
    cout << elem << ' ';
  }
  cout << endl;

  transform(vi.cbegin(), vi.cend(), vi.begin(), bind(multiplies(), _1, 2));
  for (const int elem : vi) {
    cout << elem << ' ';
  }
  cout << endl;
}
