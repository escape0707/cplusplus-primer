#include <algorithm>
#include <memory>
#include <utility>

#include "StrVec.h"

using std::destroy;
using std::pair;
using std::uninitialized_copy, std::uninitialized_move;

using size_type = StrVec::size_type;
using iterator = StrVec::iterator;

StrVec::StrVec() = default;

StrVec::StrVec(const StrVec &other) {
  pair<iterator, iterator> newdata = alloc_n_copy(other.begin(), other.end());
  elements = newdata.first;
  first_free = cap = newdata.second;
}

StrVec &StrVec::operator=(const StrVec &rhs) {
  pair<iterator, iterator> newdata = alloc_n_copy(rhs.begin(), rhs.end());
  free();
  elements = newdata.first;
  first_free = cap = newdata.second;
  return *this;
}

StrVec::~StrVec() {
  free();
}

void StrVec::push_back(const_reference value) {
  chk_n_alloc();
  Alloc_traits::construct(alloc, first_free++, value);
}

size_type StrVec::size() const {
  return first_free - elements;
}

size_type StrVec::capacity() const {
  return cap - elements;
}

iterator StrVec::begin() const {
  return elements;
}

iterator StrVec::end() const {
  return first_free;
}

iterator StrVec::allocate(size_type n) {
  if (n) {
    return Alloc_traits::allocate(alloc, n);
  }
  return nullptr;
}

pair<iterator, iterator> StrVec::alloc_n_copy(const_iterator beg,
                                              const_iterator end) {
  iterator newbeg = allocate(end - beg);
  return {newbeg, uninitialized_copy(beg, end, newbeg)};
}

pair<iterator, iterator> StrVec::alloc_n_move(iterator beg, iterator end) {
  iterator newbeg = allocate(end - beg);
  return {newbeg, uninitialized_move(beg, end, newbeg)};
}

void StrVec::chk_n_alloc() {
  if (first_free == cap) {
    reallocate();
  }
}

void StrVec::free() {
  if (elements) {
    destroy(elements, first_free);
    Alloc_traits::deallocate(alloc, elements, capacity());
  }
}

void StrVec::reallocate() {
  size_type newcapacity = size() ? 2 * size() : 1;  // todo
  iterator newelements = allocate(newcapacity);
  iterator newfirst_free =
      uninitialized_move(elements, first_free, newelements);
  free();
  elements = newelements;
  first_free = newfirst_free;
  cap = newelements + newcapacity;
}
