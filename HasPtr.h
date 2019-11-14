#pragma once

#include <cstddef>
#include <iostream>
#include <string>

class HasPtr {
  friend void swap(HasPtr &lhs, HasPtr &rhs);
  friend bool operator<(const HasPtr &lhs, const HasPtr &rhs);
  friend std::ostream &operator<<(std::ostream &os, const HasPtr &rhs);

 public:
  using element_type = std::string;
  using pointer = element_type *;
  using const_reference = const element_type &;
  HasPtr();
  HasPtr(const_reference value);
  HasPtr(const HasPtr &other);
  HasPtr(HasPtr &&other) noexcept;
  // HasPtr &operator=(HasPtr rhs);
  HasPtr &operator=(const HasPtr &rhs);
  ~HasPtr();

 private:
  using count_type = long;
  void free();
  pointer ps = nullptr;
  int i;
  count_type *use = nullptr;
};
