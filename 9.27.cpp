#include <forward_list>
#include <iostream>

using std::cout, std::endl;
using std::forward_list;

int main() {
  forward_list<int> iflist{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  for (forward_list<int>::const_iterator prev = iflist.cbefore_begin(),
                                         curr = iflist.cbegin();
       curr != iflist.cend();) {
    if (*curr & 1) {
      curr = iflist.erase_after(prev);
    } else {
      prev = curr++;
    }
  }

  for (const int &elem : iflist) {
    cout << elem << ' ';
  }
  cout << endl;
}