#include <string>

#include "HasPtr.h"

using std::string;

HasPtr::HasPtr(const string &s) : ps(new string(s)), i(0) {}

HasPtr::HasPtr(const HasPtr &other) : ps(new string(*other.ps)), i(other.i) {}

HasPtr &HasPtr::operator=(const HasPtr &rhs) {
  *ps = *rhs.ps;
  i = rhs.i;
  return *this;
}
