#ifndef HASPTR_H
#define HASPTR_H

#include <cstddef>
#include <string>

class HasPtr {
 public:
  HasPtr() = default;
  HasPtr(const std::string &s) : ps(new std::string(s)) {}
  HasPtr(const HasPtr &other) : ps(other.ps), i(other.i), use(other.use) {
    ++*use;
  }
  HasPtr &operator=(const HasPtr &rhs) {
    ++*rhs.use;
    if (--*use == 0) {
      delete use;
      delete ps;
    }
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
    return *this;
  }
  ~HasPtr() {
    if (--*use == 0) {
      delete use;
      delete ps;
    }
  }

 private:
  std::string *ps = new std::string();
  int i = 0;
  std::size_t *use = new std::size_t(1);
};

#endif
