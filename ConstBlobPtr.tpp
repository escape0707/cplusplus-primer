#include <memory>
#include <stdexcept>
#include <string>

#include "ConstBlobPtr.h"
#include "Blob.h"

using std::out_of_range, std::runtime_error;
using std::shared_ptr;
using std::string;

using container_type = ConstBlobPtr::container_type;
using difference_type = ConstBlobPtr::difference_type;
using const_reference = ConstBlobPtr::const_reference;
using const_pointer = ConstBlobPtr::const_pointer;

ConstBlobPtr::ConstBlobPtr() : curr(0) {}

ConstBlobPtr::ConstBlobPtr(const Blob &b, size_type sz)
    : wptr(b.data), curr(sz) {}

shared_ptr<container_type> ConstBlobPtr::check(size_type i,
                                                  const string &msg) const {
  shared_ptr<container_type> ret = wptr.lock();
  if (!ret) {
    throw runtime_error("unbound ConstBlobPtr");
  }
  if (i >= ret->size()) {
    throw out_of_range(msg);
  }
  return ret;
}

const_reference ConstBlobPtr::operator*() const {
  shared_ptr<container_type> p = check(curr, "dereference past end");
  return (*p)[curr];
}

const_pointer ConstBlobPtr::operator->() const {
  return &**this;
}

const_reference ConstBlobPtr::operator[](size_type pos) const {
  pos += curr;
  shared_ptr<container_type> p = check(pos, "dereference past end");
  return (*p)[pos];
}

ConstBlobPtr &ConstBlobPtr::operator++() {
  check(curr, "increment past end of ConstBlobPtr");
  ++curr;
  return *this;
}

ConstBlobPtr &ConstBlobPtr::operator--() {
  --curr;
  check(curr, "decrement past begin of ConstBlobPtr");
  return *this;
}

ConstBlobPtr ConstBlobPtr::operator++(int) {
  ConstBlobPtr ret = *this;
  ++*this;
  return ret;
}

ConstBlobPtr ConstBlobPtr::operator--(int) {
  ConstBlobPtr ret = *this;
  --*this;
  return ret;
}

ConstBlobPtr &ConstBlobPtr::operator+=(difference_type n) {
  curr = static_cast<size_type>(static_cast<difference_type>(curr) + n);
  check(curr - 1, "increment past end of ConstBlobPtr");
  return *this;
}

ConstBlobPtr &ConstBlobPtr::operator-=(difference_type n) {
  curr = static_cast<size_type>(static_cast<difference_type>(curr) - n);
  check(curr, "increment past end of ConstBlobPtr");
  return *this;
}

ConstBlobPtr ConstBlobPtr::operator+(difference_type n) const {
  ConstBlobPtr ret = *this;
  ret += n;
  return ret;
}

ConstBlobPtr ConstBlobPtr::operator-(difference_type n) const {
  ConstBlobPtr ret = *this;
  ret -= n;
  return ret;
}

ConstBlobPtr operator+(difference_type n, const ConstBlobPtr &it) {
  return it + n;
}

ConstBlobPtr operator-(difference_type n, const ConstBlobPtr &it) {
  return it - n;
}
