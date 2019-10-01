#include <iostream>
#include <iterator>
#include <list>
#include <vector>

using std::cout, std::endl;
using std::list;
using std::vector;

int main() {
  int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};

  vector<int> ivec(ia, std::end(ia));
  list<int> ilist(ia, std::end(ia));

  for (auto it = ilist.cbegin(); it != ilist.cend();) {
    if (*it & 1) {
      it = ilist.erase(it);
    } else {
      ++it;
    }
  }

  for (auto it = ivec.cbegin(); it != ivec.cend();) {
    if (*it & 1) {
      ++it;
    } else {
      it = ivec.erase(it);
    }
  }

  cout << "ilist: ";
  for (const auto &elem : ilist) {
    cout << elem << ' ';
  }
  cout << "\nivec: ";
  for (const auto &elem : ivec) {
    cout << elem << ' ';
  }
  cout << endl;
}