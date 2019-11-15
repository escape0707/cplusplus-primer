#pragma once

#include <cstddef>
#include <iostream>
#include <memory>
#include <utility>

class String {
 public:
  using value_type = char;
  using allocator_type = std::allocator<value_type>;
  using size_type = std::size_t;
  using difference_type = std::ptrdiff_t;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = value_type *;
  using const_iterator = const value_type *;
  String();
  String(const_iterator str);
  String(const String &other);
  String(String &&other) noexcept;
  String &operator=(const String &rhs);
  String &operator=(String &&rhs) noexcept;
  ~String();
  iterator begin();
  const_iterator begin() const;
  const_iterator cbegin() const;
  iterator end();
  const_iterator end() const;
  const_iterator cend() const;
  size_type size() const;
  size_type length() const;
  size_type capacity() const;

 private:
  using Alloc_traits = std::allocator_traits<allocator_type>;
  inline static allocator_type alloc;
  static iterator allocate(size_type n);
  static std::pair<iterator, iterator> alloc_and_copy(const_iterator beg,
                                                      const_iterator end);
  // static std::pair<iterator, iterator> alloc_and_copy_n(const_iterator beg,
  //                                                       size_type n);
  void free();
  iterator elements = nullptr;
  iterator first_free = nullptr;
};

bool operator==(const String &lhs, const String &rhs);
bool operator!=(const String &lhs, const String &rhs);
bool operator<(const String &lhs, const String &rhs);
bool operator>(const String &lhs, const String &rhs);
bool operator<=(const String &lhs, const String &rhs);
bool operator>=(const String &lhs, const String &rhs);
std::ostream &operator<<(std::ostream &os, const String &rhs);
