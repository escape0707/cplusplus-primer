#ifndef HASPTR_H
#define HASPTR_H

#include <string>

class HasPtr {
 public:
  HasPtr(const std::string &s = std::string());
  HasPtr(const HasPtr &other);
  HasPtr &operator=(const HasPtr &rhs);

 private:
  std::string *ps;
  int i;
};

#endif
