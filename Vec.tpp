#pragma once

#include <algorithm>
#include <initializer_list>
#include <memory>
#include <utility>

#include "Vec.h"

template <typename T>
Vec<T>::Vec() = default;

template <typename T>
Vec<T>::Vec(const Vec &other) {
  std::pair<iterator, iterator> newdata =
      alloc_n_copy(other.begin(), other.end());
  elements = newdata.first;
  first_free = cap = newdata.second;
}

template <typename T>
Vec<T>::Vec(Vec &&other) noexcept
    : elements(other.elements), first_free(other.first_free), cap(other.cap) {
  other.elements = nullptr;
  // other.elements = other.first_free = other.cap = nullptr;
}

// copying a initializer_list does not copy the underlying objects
template <typename T>
Vec<T>::Vec(std::initializer_list<value_type> il) {
  // so sad that initializer_list was too old to support move semantics.
  // and it provides only const iterator to its underlying data structure.
  std::pair<iterator, iterator> newdata = alloc_n_copy(il.begin(), il.end());
  elements = newdata.first;
  first_free = cap = newdata.second;
}

template <typename T>
Vec<T> &Vec<T>::operator=(const Vec &rhs) {
  std::pair<iterator, iterator> newdata = alloc_n_copy(rhs.begin(), rhs.end());
  free();
  elements = newdata.first;
  first_free = cap = newdata.second;
  return *this;
}

template <typename T>
Vec<T> &Vec<T>::operator=(Vec &&rhs) noexcept {
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

template <typename T>
Vec<T> &Vec<T>::operator=(std::initializer_list<value_type> il) {
  std::pair<iterator, iterator> newdata = alloc_n_copy(il.begin(), il.end());
  free();
  elements = newdata.first;
  first_free = cap = newdata.second;
  return *this;
}

template <typename T>
Vec<T>::~Vec() {
  free();
}

template <typename T>
void Vec<T>::push_back(const_reference value) {
  chk_n_alloc();
  Alloc_traits::construct(alloc, first_free++, value);
}

template <typename T>
void Vec<T>::push_back(value_type &&value) {
  chk_n_alloc();
  Alloc_traits::construct(alloc, first_free++, std::move(value));
}

template <typename T>
void Vec<T>::pop_back() {
  std::destroy_at(--first_free);
}

template <typename T>
void Vec<T>::resize(size_type new_size) {
  if (new_size < size()) {
    destroy_starting_from(elements + new_size);
  } else if (size_type diff = new_size - size()) {
    reserve(new_size);
    first_free = std::uninitialized_value_construct_n(first_free, diff);
  }
}

template <typename T>
void Vec<T>::resize(size_type new_size, const_reference value) {
  if (new_size < size()) {
    destroy_starting_from(elements + new_size);
  } else if (size_type diff = new_size - size()) {
    reserve(new_size);
    first_free = std::uninitialized_fill_n(first_free, diff, value);
  }
}

template <typename T>
bool Vec<T>::empty() const {
  return elements == first_free;
}

template <typename T>
typename Vec<T>::size_type Vec<T>::size() const {
  return static_cast<size_type>(first_free - elements);
}

template <typename T>
void Vec<T>::reserve(size_type new_cap) {
  if (new_cap > capacity()) {
    _reserve(new_cap);
  }
}

template <typename T>
typename Vec<T>::size_type Vec<T>::capacity() const {
  return static_cast<size_type>(cap - elements);
}

template <typename T>
typename Vec<T>::reference Vec<T>::operator[](size_type pos) {
  return const_cast<reference>(std::as_const(*this)[pos]);
}

template <typename T>
typename Vec<T>::const_reference Vec<T>::operator[](size_type pos) const {
  return elements[pos];
}

template <typename T>
typename Vec<T>::reference Vec<T>::front() {
  return const_cast<reference>(std::as_const(*this).front());
}

template <typename T>
typename Vec<T>::const_reference Vec<T>::front() const {
  return *elements;
}

template <typename T>
typename Vec<T>::reference Vec<T>::back() {
  return const_cast<reference>(std::as_const(*this).back());
}

template <typename T>
typename Vec<T>::const_reference Vec<T>::back() const {
  return first_free[-1];
}

template <typename T>
typename Vec<T>::iterator Vec<T>::begin() {
  return const_cast<iterator>(std::as_const(*this).begin());
}

template <typename T>
typename Vec<T>::const_iterator Vec<T>::begin() const {
  return cbegin();
}

template <typename T>
typename Vec<T>::const_iterator Vec<T>::cbegin() const {
  return elements;
}

template <typename T>
typename Vec<T>::iterator Vec<T>::end() {
  return const_cast<iterator>(std::as_const(*this).end());
}

template <typename T>
typename Vec<T>::const_iterator Vec<T>::end() const {
  return cend();
}

template <typename T>
typename Vec<T>::const_iterator Vec<T>::cend() const {
  return first_free;
}

template <typename T>
bool operator==(const Vec<T> &lhs, const Vec<T> &rhs) {
  return std::equal(lhs.cbegin(), lhs.cend(), rhs.cbegin(), rhs.cend());
}

template <typename T>
bool operator!=(const Vec<T> &lhs, const Vec<T> &rhs) {
  return !(lhs == rhs);
}

template <typename T>
bool operator<(const Vec<T> &lhs, const Vec<T> &rhs) {
  return std::lexicographical_compare(lhs.cbegin(), lhs.cend(), rhs.cbegin(),
                                      rhs.cend());
}

template <typename T>
bool operator>(const Vec<T> &lhs, const Vec<T> &rhs) {
  return rhs < lhs;
}

template <typename T>
bool operator<=(const Vec<T> &lhs, const Vec<T> &rhs) {
  return !(lhs > rhs);
}

template <typename T>
bool operator>=(const Vec<T> &lhs, const Vec<T> &rhs) {
  return !(lhs < rhs);
}

template <typename T>
typename Vec<T>::iterator Vec<T>::allocate(size_type n) {
  if (n) {
    return Alloc_traits::allocate(alloc, n);
  }
  return nullptr;
}

template <typename T>
std::pair<typename Vec<T>::iterator, typename Vec<T>::iterator>
Vec<T>::alloc_n_copy(const_iterator beg, const_iterator end) {
  iterator newbeg = allocate(static_cast<size_type>(end - beg));
  return {newbeg, std::uninitialized_copy(beg, end, newbeg)};
}

template <typename T>
void Vec<T>::destroy_starting_from(iterator pos) {
  std::destroy(pos, first_free);
  first_free = pos;
}

template <typename T>
void Vec<T>::_reserve(size_type new_cap) {
  iterator newelements = allocate(new_cap);
  iterator newfirst_free =
      std::uninitialized_move(elements, first_free, newelements);
  free();
  elements = newelements;
  first_free = newfirst_free;
  cap = newelements + new_cap;
}

template <typename T>
void Vec<T>::chk_n_alloc() {
  if (first_free == cap) {
    _reserve(capacity() ? 2 * capacity() : 1);
  }
}

template <typename T>
void Vec<T>::free() {
  if (elements) {
    std::destroy(elements, first_free);
    Alloc_traits::deallocate(alloc, elements, capacity());
  }
}
