#include "Vec.h"

#include <algorithm>
#include <initializer_list>
#include <memory>
#include <utility>

Vec::Vec() = default;

Vec::Vec(const Vec &other) {
  std::pair<iterator, iterator> newdata =
      alloc_n_copy(other.begin(), other.end());
  elements = newdata.first;
  first_free = cap = newdata.second;
}

Vec::Vec(Vec &&other) noexcept
    : elements(other.elements), first_free(other.first_free), cap(other.cap) {
  other.elements = nullptr;
  // other.elements = other.first_free = other.cap = nullptr;
}

// copying a initializer_list does not copy the underlying objects
Vec::Vec(std::initializer_list<value_type> il) {
  // so sad that initializer_list was too old to support move semantics.
  // and it provides only const iterator to its underlying data structure.
  std::pair<iterator, iterator> newdata = alloc_n_copy(il.begin(), il.end());
  elements = newdata.first;
  first_free = cap = newdata.second;
}

Vec &Vec::operator=(const Vec &rhs) {
  std::pair<iterator, iterator> newdata = alloc_n_copy(rhs.begin(), rhs.end());
  free();
  elements = newdata.first;
  first_free = cap = newdata.second;
  return *this;
}

Vec &Vec::operator=(Vec &&rhs) noexcept {
  if (this != &rhs) {
    free();
    elements = rhs.elements;
    first_free = rhs.first_free;
    cap = rhs.cap;
    rhs.elements = nullptr;
    // rhs.elements = rhs.first_free = rhs.cap = nullptr;
  }
  return *this;
}

Vec &Vec::operator=(std::initializer_list<value_type> il) {
  std::pair<iterator, iterator> newdata = alloc_n_copy(il.begin(), il.end());
  free();
  elements = newdata.first;
  first_free = cap = newdata.second;
  return *this;
}

Vec::~Vec() {
  free();
}

void Vec::push_back(const_reference value) {
  chk_n_alloc();
  Alloc_traits::construct(alloc, first_free++, value);
}

void Vec::push_back(value_type &&value) {
  chk_n_alloc();
  Alloc_traits::construct(alloc, first_free++, std::move(value));
}

void Vec::pop_back() {
  std::destroy_at(--first_free);
}

void Vec::resize(size_type new_size) {
  if (new_size < size()) {
    destroy_starting_from(elements + new_size);
  } else if (size_type diff = new_size - size()) {
    reserve(new_size);
    first_free = std::uninitialized_value_construct_n(first_free, diff);
  }
}

void Vec::resize(size_type new_size, const_reference value) {
  if (new_size < size()) {
    destroy_starting_from(elements + new_size);
  } else if (size_type diff = new_size - size()) {
    reserve(new_size);
    first_free = std::uninitialized_fill_n(first_free, diff, value);
  }
}

bool Vec::empty() const {
  return elements == first_free;
}

Vec::size_type Vec::size() const {
  return static_cast<size_type>(first_free - elements);
}

void Vec::reserve(size_type new_cap) {
  if (new_cap > capacity()) {
    _reserve(new_cap);
  }
}

Vec::size_type Vec::capacity() const {
  return static_cast<size_type>(cap - elements);
}

Vec::reference Vec::operator[](size_type pos) {
  return const_cast<reference>(std::as_const(*this)[pos]);
}

Vec::const_reference Vec::operator[](size_type pos) const {
  return elements[pos];
}

Vec::reference Vec::front() {
  return const_cast<reference>(std::as_const(*this).front());
}

Vec::const_reference Vec::front() const {
  return *elements;
}

Vec::reference Vec::back() {
  return const_cast<reference>(std::as_const(*this).back());
}

Vec::const_reference Vec::back() const {
  return first_free[-1];
}

Vec::iterator Vec::begin() {
  return const_cast<iterator>(std::as_const(*this).begin());
}

Vec::const_iterator Vec::begin() const {
  return cbegin();
}

Vec::const_iterator Vec::cbegin() const {
  return elements;
}

Vec::iterator Vec::end() {
  return const_cast<iterator>(std::as_const(*this).end());
}

Vec::const_iterator Vec::end() const {
  return cend();
}

Vec::const_iterator Vec::cend() const {
  return first_free;
}

bool operator==(const Vec &lhs, const Vec &rhs) {
  return std::equal(lhs.cbegin(), lhs.cend(), rhs.cbegin(), rhs.cend());
}

bool operator!=(const Vec &lhs, const Vec &rhs) {
  return !(lhs == rhs);
}

bool operator<(const Vec &lhs, const Vec &rhs) {
  return std::lexicographical_compare(lhs.cbegin(), lhs.cend(), rhs.cbegin(),
                                      rhs.cend());
}

bool operator>(const Vec &lhs, const Vec &rhs) {
  return rhs < lhs;
}

bool operator<=(const Vec &lhs, const Vec &rhs) {
  return !(lhs > rhs);
}

bool operator>=(const Vec &lhs, const Vec &rhs) {
  return !(lhs < rhs);
}

Vec::iterator Vec::allocate(size_type n) {
  if (n) {
    return Alloc_traits::allocate(alloc, n);
  }
  return nullptr;
}

std::pair<Vec::iterator, Vec::iterator> Vec::alloc_n_copy(const_iterator beg,
                                                          const_iterator end) {
  iterator newbeg = allocate(static_cast<size_type>(end - beg));
  return {newbeg, std::uninitialized_copy(beg, end, newbeg)};
}

void Vec::destroy_starting_from(iterator pos) {
  std::destroy(pos, first_free);
  first_free = pos;
}

void Vec::_reserve(size_type new_cap) {
  iterator newelements = allocate(new_cap);
  iterator newfirst_free =
      std::uninitialized_move(elements, first_free, newelements);
  free();
  elements = newelements;
  first_free = newfirst_free;
  cap = newelements + new_cap;
}

void Vec::chk_n_alloc() {
  if (first_free == cap) {
    _reserve(capacity() ? 2 * capacity() : 1);
  }
}

void Vec::free() {
  if (elements) {
    std::destroy(elements, first_free);
    Alloc_traits::deallocate(alloc, elements, capacity());
  }
}
