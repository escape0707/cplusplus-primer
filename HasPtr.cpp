#include <utility>

#include "HasPtr.h"

HasPtr::HasPtr() = default;

HasPtr::HasPtr(const_reference value)
    : ps(new element_type(value)), i(0), use(new count_type(1)) {}

HasPtr::HasPtr(const HasPtr &other) : ps(other.ps), i(other.i), use(other.use) {
  ++*use;
}

HasPtr::HasPtr(HasPtr &&other) noexcept
    : ps(other.ps), i(other.i), use(other.use) {
  // other.ps = nullptr;
  other.use = nullptr;
}

HasPtr &HasPtr::operator=(HasPtr rhs) {
  swap(*this, rhs);
  return *this;
}

// HasPtr &HasPtr::operator=(const HasPtr &rhs) {
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

HasPtr::~HasPtr() {
  if (use && --*use == 0) {
    delete use;
    delete ps;
  }
}

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
