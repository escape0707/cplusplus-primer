// see also Blob.h & Blob.tpp

#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <vector>

#include "Blob.h"

using std::begin, std::end;
using std::cout, std::endl;
using std::list;
using std::string;
using std::vector;

int main() {
  int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  vector<long> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  list<const char *> w = {"now", "is", "the", "time"};

  Blob<int> a1(begin(ia), end(ia));
  for (auto b = begin(a1), e = end(a1); b != e; ++b) {
    cout << *b << ' ';
  }
  cout << endl;

  Blob<long> a2(begin(vi), end(vi));
  for (auto b = begin(a2), e = end(a2); b != e; ++b) {
    cout << *b << ' ';
  }
  cout << endl;

  Blob<const char *> a3(begin(w), end(w));
  for (auto b = begin(a3), e = end(a3); b != e; ++b) {
    cout << *b << ' ';
  }
  cout << endl;
}
