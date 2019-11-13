#pragma once

#include <cstddef>
#include <iostream>
#include <string>

class HasPtr {
  friend void swap(HasPtr &lhs, HasPtr &rhs);
  friend bool operator<(const HasPtr &lhs, const HasPtr &rhs);
  friend std::ostream &operator<<(std::ostream &os, const HasPtr &rhs);

 public:
  HasPtr() = default;
  HasPtr(const std::string &s)
      : ps(new std::string(s)), i(0), use(new std::size_t(1)) {}
  HasPtr(const HasPtr &other) : ps(other.ps), i(other.i), use(other.use) {
    ++*use;
  }
  HasPtr(HasPtr &&other) noexcept : ps(other.ps), i(other.i), use(other.use) {
    // other.ps = nullptr;
    other.use = nullptr;
  }
  HasPtr &operator=(HasPtr rhs) {
    swap(*this, rhs);
    return *this;
  }
  // HasPtr &operator=(const HasPtr &rhs) {
  //   ++*rhs.use;
  //   if (--*use == 0) {
  //     delete use;
  //     delete ps;
  //   }
  //   ps = rhs.ps;
  //   i = rhs.i;
  //   use = rhs.use;
  //   return *this;
  // }
  ~HasPtr() {
    if (use && --*use == 0) {
      delete use;
      delete ps;
    }
  }

 private:
  std::string *ps = nullptr;
  int i;
  std::size_t *use = nullptr;
};

void swap(HasPtr &lhs, HasPtr &rhs) {
  std::cerr << "Entering swap" << std::endl;
  using std::swap;
  swap(lhs.ps, rhs.ps);
  swap(lhs.i, rhs.i);
  swap(lhs.use, rhs.use);
}

bool operator<(const HasPtr &lhs, const HasPtr &rhs) {
  return *lhs.ps < *rhs.ps;
}

std::ostream &operator<<(std::ostream &os, const HasPtr &rhs) {
  return os << *rhs.ps;
}
