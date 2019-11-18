#include <memory>
#include <stdexcept>
#include <string>

#include "StrBlob.h"
#include "StrBlobPtr.h"

using std::out_of_range, std::runtime_error;
using std::shared_ptr;
using std::string;

using container_type = StrBlobPtr::container_type;
using difference_type = StrBlobPtr::difference_type;
using reference = StrBlobPtr::reference;

StrBlobPtr::StrBlobPtr() : curr(0) {}

StrBlobPtr::StrBlobPtr(StrBlob &b, size_type sz) : wptr(b.data), curr(sz) {}

shared_ptr<container_type> StrBlobPtr::check(size_type i,
                                             const string &msg) const {
  shared_ptr<container_type> ret = wptr.lock();
  if (!ret) {
    throw runtime_error("unbound StrBlobPtr");
  }
  if (i >= ret->size()) {
    throw out_of_range(msg);
  }
  return ret;
}

reference StrBlobPtr::deref() const {
  shared_ptr<container_type> p = check(curr, "dereference past end");
  return (*p)[curr];
}

reference StrBlobPtr::operator[](size_type pos) const {
  pos += curr;
  shared_ptr<container_type> p = check(pos, "dereference past end");
  return (*p)[pos];
}

StrBlobPtr &StrBlobPtr::operator++() {
  check(curr, "increment past end of StrBlobPtr");
  ++curr;
  return *this;
}

StrBlobPtr &StrBlobPtr::operator--() {
  --curr;
  check(curr, "decrement past begin of StrBlobPtr");
  return *this;
}

StrBlobPtr StrBlobPtr::operator++(int) {
  StrBlobPtr ret = *this;
  ++*this;
  return ret;
}

StrBlobPtr StrBlobPtr::operator--(int) {
  StrBlobPtr ret = *this;
  --*this;
  return ret;
}

StrBlobPtr &StrBlobPtr::operator+=(difference_type n) {
  curr += n;
  check(curr - 1, "increment past end of StrBlobPtr");
  return *this;
}

StrBlobPtr &StrBlobPtr::operator-=(difference_type n) {
  curr -= n;
  check(curr, "increment past end of StrBlobPtr");
  return *this;
}

StrBlobPtr StrBlobPtr::operator+(difference_type n) const {
  StrBlobPtr ret = *this;
  ret += n;
  return ret;
}

StrBlobPtr StrBlobPtr::operator-(difference_type n) const {
  StrBlobPtr ret = *this;
  ret -= n;
  return ret;
}

StrBlobPtr operator+(difference_type n, const StrBlobPtr &it) {
  return it + n;
}

StrBlobPtr operator-(difference_type n, const StrBlobPtr &it) {
  return it - n;
}
