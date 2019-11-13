#include <algorithm>
#include <cstring>
#include <iostream>
#include <memory>
#include <utility>

#include "String.h"

using std::as_const, std::pair;
using std::cerr, std::endl;
using std::destroy;
using std::strchr;
using std::uninitialized_copy;
// using std::uninitialized_copy_n;

using size_type = String::size_type;
using iterator = String::iterator;
using const_iterator = String::const_iterator;

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

String &String::operator=(const String &rhs) {
  cerr << "Entered: String &String::operator=(const String &rhs)" << endl;
  pair<iterator, iterator> newdata = alloc_and_copy(rhs.cbegin(), rhs.cend());
  free();
  elements = newdata.first;
  first_free = newdata.second;
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
