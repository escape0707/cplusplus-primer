#include <cstddef>
#include <iostream>
#include <utility>
#include <memory>
#include <string>

using std::allocator, std::allocator_traits;
using std::cin, std::cout, std::endl;
using std::size_t;
using std::string;

int main() {
  using Alloc = allocator<string>;
  using Alloc_traits = allocator_traits<Alloc>;

  Alloc alloc;
  size_t n = 42;
  string *const p = Alloc_traits::allocate(alloc, n);

  string *q = p;
  for (string s; cin >> s && q != p + n; ++q) {
    Alloc_traits::construct(alloc, q, std::move(s));
  }

  const size_t size = q - p;
  for (const string *beg = p, *end = p + size; beg != end; ++beg) {
    cout << *beg << ' ';
  }
  cout << endl;

  while (q != p) {
    Alloc_traits::destroy(alloc, --q);
  }
}
