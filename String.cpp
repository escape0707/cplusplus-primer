#include <algorithm>
#include <cstring>
#include <iostream>
#include <iterator>
#include <memory>
#include <utility>

#include "String.h"

using std::as_const, std::pair;
using std::cerr, std::endl, std::ostream;
using std::copy, std::equal, std::lexicographical_compare,
    std::uninitialized_copy;
using std::destroy;
using std::ostream_iterator;
using std::strchr;
// using std::uninitialized_copy_n;

using value_type = String::value_type;
using size_type = String::size_type;
using iterator = String::iterator;
using const_iterator = String::const_iterator;

String::String() = default;

String::String(const_iterator str) {
  pair<iterator, iterator> newdata = alloc_and_copy(str, strchr(str, '\0'));
  elements = newdata.first;
  first_free = newdata.second;
}

String::String(const String &other) {
  cerr << "Entered: String::String(const String &other)" << endl;
  pair<iterator, iterator> newdata =
      alloc_and_copy(other.cbegin(), other.cend());
  elements = newdata.first;
  first_free = newdata.second;
}

String::String(String &&other) noexcept {
  cerr << "Entered: String::String(String &&other)" << endl;
  elements = other.elements;
  first_free = other.first_free;
  elements = first_free = nullptr;
}

String &String::operator=(const String &rhs) {
  cerr << "Entered: String &String::operator=(const String &rhs)" << endl;
  pair<iterator, iterator> newdata = alloc_and_copy(rhs.cbegin(), rhs.cend());
  free();
  elements = newdata.first;
  first_free = newdata.second;
  return *this;
}

String &String::operator=(String &&rhs) noexcept {
  cerr << "Entered: String &String::operator=(String &&rhs)" << endl;
  if (this != &rhs) {
    free();
    elements = rhs.elements;
    first_free = rhs.first_free;
    elements = first_free = nullptr;
  }
  return *this;
}

String::~String() {
  free();
}

iterator String::begin() {
  return const_cast<iterator>(as_const(*this).begin());
}

const_iterator String::begin() const {
  return cbegin();
}

const_iterator String::cbegin() const {
  return elements;
}

iterator String::end() {
  return const_cast<iterator>(as_const(*this).end());
}

const_iterator String::end() const {
  return cend();
}

const_iterator String::cend() const {
  return first_free;
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

bool operator==(const String &lhs, const String &rhs) {
  return equal(lhs.cbegin(), lhs.cend(), rhs.cbegin(), rhs.cend());
}

bool operator!=(const String &lhs, const String &rhs) {
  return !(lhs == rhs);
}

bool operator<(const String &lhs, const String &rhs) {
  return lexicographical_compare(lhs.cbegin(), lhs.cend(), rhs.cbegin(),
                                 rhs.cend());
}

bool operator>(const String &lhs, const String &rhs) {
  return rhs < lhs;
}

bool operator<=(const String &lhs, const String &rhs) {
  return !(lhs > rhs);
}

bool operator>=(const String &lhs, const String &rhs) {
  return !(lhs < rhs);
}

ostream &operator<<(ostream &os, const String &rhs) {
  copy(rhs.cbegin(), rhs.cend(), ostream_iterator<value_type>(os));
  return os;
}

iterator String::allocate(size_type n) {
  if (n) {
    return Alloc_traits::allocate(alloc, n);
  }
  return nullptr;
}

pair<iterator, iterator> String::alloc_and_copy(const_iterator beg,
                                                const_iterator end) {
  iterator newbeg = allocate(end - beg);
  return {newbeg, uninitialized_copy(beg, end, newbeg)};
}

// std::pair<iterator, iterator> String::alloc_and_copy_n(const_iterator beg,
//                                                        size_type n) {
//   iterator newbeg = allocate(n);
//   return {newbeg, uninitialized_copy_n(beg, n, newbeg)};
// }

void String::free() {
  if (elements) {
    destroy(elements, first_free);
    Alloc_traits::deallocate(alloc, elements, capacity());
  }
}
