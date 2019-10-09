#include <deque>
#include <forward_list>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

using std::back_inserter, std::front_inserter, std::inserter;
using std::cout, std::endl;
using std::deque;
using std::forward_list;
using std::list;
using std::ostream_iterator;
using std::vector;

int main() {
  vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  deque<int> ideq;
  forward_list<int> iflst;
  list<int> ilst;

  copy(ivec.cbegin(), ivec.cend(), back_inserter(ideq));
  copy(ivec.cbegin(), ivec.cend(), front_inserter(iflst));
  copy(ivec.cbegin(), ivec.cend(), inserter(ilst, ilst.begin()));

  copy(ideq.cbegin(), ideq.cend(), ostream_iterator<int>(cout, " "));
  cout << endl;
  copy(iflst.cbegin(), iflst.cend(), ostream_iterator<int>(cout, " "));
  cout << endl;
  copy(ilst.cbegin(), ilst.cend(), ostream_iterator<int>(cout, " "));
  cout << endl;
}