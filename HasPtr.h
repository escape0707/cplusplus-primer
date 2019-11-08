#ifndef HASPTR_H
#define HASPTR_H

#include <string>

class HasPtr {
 public:
  HasPtr() = default;
  HasPtr(const std::string &s) : ps(new std::string(s)) {}
  HasPtr(const HasPtr &other) : ps(new std::string(*other.ps)), i(other.i) {}
  HasPtr &operator=(const HasPtr &rhs) {
    *ps = *rhs.ps;
    i = rhs.i;
    return *this;
  }
  ~HasPtr() { delete ps; }

 private:
  std::string *ps = new std::string();
  int i = 0;
};

#endif
