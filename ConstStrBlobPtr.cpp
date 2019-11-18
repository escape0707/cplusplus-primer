#include <memory>
#include <stdexcept>
#include <string>

#include "ConstStrBlobPtr.h"
#include "StrBlob.h"

using std::out_of_range, std::runtime_error;
using std::shared_ptr;
using std::string;

using container_type = ConstStrBlobPtr::container_type;
using difference_type = ConstStrBlobPtr::difference_type;
using const_reference = ConstStrBlobPtr::const_reference;

ConstStrBlobPtr::ConstStrBlobPtr() : curr(0) {}

ConstStrBlobPtr::ConstStrBlobPtr(const StrBlob &b, size_type sz)
    : wptr(b.data), curr(sz) {}

shared_ptr<container_type> ConstStrBlobPtr::check(size_type i,
                                                  const string &msg) const {
  shared_ptr<container_type> ret = wptr.lock();
  if (!ret) {
    throw runtime_error("unbound ConstStrBlobPtr");
  }
  if (i >= ret->size()) {
    throw out_of_range(msg);
  }
  return ret;
}

const_reference ConstStrBlobPtr::deref() const {
  shared_ptr<container_type> p = check(curr, "dereference past end");
  return (*p)[curr];
}

const_reference ConstStrBlobPtr::operator[](size_type pos) const {
  pos += curr;
  shared_ptr<container_type> p = check(pos, "dereference past end");
  return (*p)[pos];
}

ConstStrBlobPtr &ConstStrBlobPtr::operator++() {
  check(curr, "increment past end of ConstStrBlobPtr");
  ++curr;
  return *this;
}

ConstStrBlobPtr &ConstStrBlobPtr::operator--() {
  --curr;
  check(curr, "decrement past begin of ConstStrBlobPtr");
  return *this;
}

ConstStrBlobPtr ConstStrBlobPtr::operator++(int) {
  ConstStrBlobPtr ret = *this;
  ++*this;
  return ret;
}

ConstStrBlobPtr ConstStrBlobPtr::operator--(int) {
  ConstStrBlobPtr ret = *this;
  --*this;
  return ret;
}

ConstStrBlobPtr &ConstStrBlobPtr::operator+=(difference_type n) {
  curr += n;
  check(curr - 1, "increment past end of ConstStrBlobPtr");
  return *this;
}

ConstStrBlobPtr &ConstStrBlobPtr::operator-=(difference_type n) {
  curr -= n;
  check(curr, "increment past end of ConstStrBlobPtr");
  return *this;
}

ConstStrBlobPtr ConstStrBlobPtr::operator+(difference_type n) const {
  ConstStrBlobPtr ret = *this;
  ret += n;
  return ret;
}

ConstStrBlobPtr ConstStrBlobPtr::operator-(difference_type n) const {
  ConstStrBlobPtr ret = *this;
  ret -= n;
  return ret;
}

ConstStrBlobPtr operator+(difference_type n, const ConstStrBlobPtr &it) {
  return it + n;
}

ConstStrBlobPtr operator-(difference_type n, const ConstStrBlobPtr &it) {
  return it - n;
}
