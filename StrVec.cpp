#include <algorithm>
#include <initializer_list>
#include <memory>
#include <utility>

#include "StrVec.h"

using std::destroy;
using std::initializer_list;
using std::pair;
using std::uninitialized_copy;
using std::uninitialized_fill_n;
using std::uninitialized_move;
using std::uninitialized_value_construct_n;

using size_type = StrVec::size_type;
using iterator = StrVec::iterator;

StrVec::StrVec() = default;

StrVec::StrVec(const StrVec &other) {
  pair<iterator, iterator> newdata = alloc_n_copy(other.begin(), other.end());
  elements = newdata.first;
  first_free = cap = newdata.second;
}

// copying a std::initializer_list does not copy the underlying objects
StrVec::StrVec(initializer_list<value_type> il) {
  // so sad that initializer_list was too old to support move semantics.
  // and it provides only const iterator to its underlying data structure.
  pair<iterator, iterator> newdata = alloc_n_copy(il.begin(), il.end());
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

void StrVec::resize(size_type count) {
  difference_type diff = count - size();
  if (diff < 0) {
    _pop_back_n(-diff);
    return;
  }
  if (diff > 0) {
    reserve(count);
    uninitialized_value_construct_n(first_free, diff);
  }
}

void StrVec::resize(size_type count, const_reference value) {
  difference_type diff = count - size();
  if (diff < 0) {
    _pop_back_n(-diff);
    return;
  }
  if (diff > 0) {
    reserve(count);
    uninitialized_fill_n(first_free, diff, value);
  }
}

size_type StrVec::size() const {
  return first_free - elements;
}

void StrVec::reserve(size_type new_cap) {
  if (new_cap > capacity()) {
    _reserve(new_cap);
  }
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

void StrVec::_pop_back_n(size_type n) {
  iterator newfirst_free = first_free - n;
  while (first_free != newfirst_free) {
    Alloc_traits::destroy(alloc, --first_free);
  }
}

void StrVec::_reserve(size_type new_cap) {
  iterator newelements = allocate(new_cap);
  iterator newfirst_free =
      uninitialized_move(elements, first_free, newelements);
  free();
  elements = newelements;
  first_free = newfirst_free;
  cap = newelements + new_cap;
}

void StrVec::chk_n_alloc() {
  if (first_free == cap) {
    _reserve(capacity() ? 2 * capacity() : 1);
  }
}

void StrVec::free() {
  if (elements) {
    destroy(elements, first_free);
    Alloc_traits::deallocate(alloc, elements, capacity());
  }
}
