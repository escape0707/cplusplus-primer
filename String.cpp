#include <algorithm>
#include <cstring>
#include <memory>
#include <utility>

#include "String.h"

using std::destroy;
using std::pair;
using std::strchr;
using std::uninitialized_copy;
// using std::uninitialized_copy_n;

using size_type = String::size_type;
using iterator = String::iterator;

String::String(const_iterator str) {
  pair<iterator, iterator> newdata = alloc_and_copy(str, strchr(str, '\0'));
  elements = newdata.first;
  first_free = newdata.second;
}

String::~String() {
  free();
}

size_type String::size() const {
  return first_free - elements;
}

size_type String::length() const {
  return size();
}

size_type String::capacity() const {
  return size();
}

std::pair<iterator, iterator> String::alloc_and_copy(const_iterator beg,
                                                     const_iterator end) {
  iterator newelements = Alloc_traits::allocate(alloc, end - beg);
  return {newelements, uninitialized_copy(beg, end, newelements)};
}

// std::pair<iterator, iterator> String::alloc_and_copy_n(const_iterator beg,
//                                                        size_type n) {
//   iterator newelements = Alloc_traits::allocate(alloc, n);
//   return {newelements, uninitialized_copy_n(beg, n, newelements)};
// }

void String::free() {
  destroy(elements, first_free);
  Alloc_traits::deallocate(alloc, elements, capacity());
}
