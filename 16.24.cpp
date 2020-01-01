// see also Blob.h & Blob.tpp

#include <iterator>
#include <list>
#include <string>
#include <vector>

#include "Blob.h"

using std::begin, std::end;
using std::list;
using std::string;
using std::vector;

int main() {
  int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  vector<long> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  list<const char *> w = {"now", "is", "the", "time"};

  Blob<int> a1(begin(ia), end(ia));
}
