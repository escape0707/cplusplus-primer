#include <algorithm>
#include <fstream>
#include <iterator>
#include <stdexcept>

using std::for_each;
using std::ifstream, std::ofstream;
using std::istream_iterator, std::ostream_iterator;
using std::runtime_error;

int main() {
  ifstream fin("a.in");
  ofstream fodd("odd.out"), feven("even.out");
  if (!(fin && fodd && feven)) {
    throw runtime_error("Failed to open files.");
  }
  istream_iterator<int> int_it(fin), eof;
  ostream_iterator<int> fodd_it(fodd, " "), feven_it(feven, "\n");
  for_each(int_it, eof,
           [&](const int &i) { (i & 1) ? *fodd_it++ = i : *feven_it++ = i; });
}