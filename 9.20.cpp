#include <deque>
#include <list>

using std::deque;
using std::list;

int main() {
  list<int> ilist{0, 1, 3, 4, 5, 6, 7, 8, 9};
  deque<int> ideq_even, ideq_odd;

  for (int & elem : ilist) {
    if (elem & 1) {
      ideq_odd.push_back(std::move(elem));
    } else {
      ideq_even.push_back(std::move(elem));
    }
  }
}