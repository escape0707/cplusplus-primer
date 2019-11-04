#include <string>

#include "HasPtr.h"

using std::string;

HasPtr::HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}

HasPtr::HasPtr(const HasPtr &other) : ps(new string(*other.ps)), i(other.i) {}
