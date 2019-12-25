#include <memory>
#include <stdexcept>
#include <string>

#include "Blob.h"
#include "ConstBlobPtr.h"

using std::out_of_range, std::runtime_error;
using std::shared_ptr;
using std::string;

Blob::ConstBlobPtr::ConstBlobPtr() : curr(0) {}

Blob::ConstBlobPtr::ConstBlobPtr(const Blob &b, size_type sz)
    : wptr(b.data), curr(sz) {}

shared_ptr<Blob::container_type> Blob::ConstBlobPtr::check(
    size_type i,
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

Blob::const_reference Blob::ConstBlobPtr::operator*() const {
  shared_ptr<container_type> p = check(curr, "dereference past end");
  return (*p)[curr];
}

Blob::const_pointer Blob::ConstBlobPtr::operator->() const {
  return &**this;
}

Blob::const_reference Blob::ConstBlobPtr::operator[](size_type pos) const {
  pos += curr;
  shared_ptr<container_type> p = check(pos, "dereference past end");
  return (*p)[pos];
}

Blob::ConstBlobPtr &Blob::ConstBlobPtr::operator++() {
  check(curr, "increment past end of ConstBlobPtr");
  ++curr;
  return *this;
}

Blob::ConstBlobPtr &Blob::ConstBlobPtr::operator--() {
  --curr;
  check(curr, "decrement past begin of ConstBlobPtr");
  return *this;
}

Blob::ConstBlobPtr Blob::ConstBlobPtr::operator++(int) {
  ConstBlobPtr ret = *this;
  ++*this;
  return ret;
}

Blob::ConstBlobPtr Blob::ConstBlobPtr::operator--(int) {
  ConstBlobPtr ret = *this;
  --*this;
  return ret;
}

Blob::ConstBlobPtr &Blob::ConstBlobPtr::operator+=(difference_type n) {
  curr = static_cast<size_type>(static_cast<difference_type>(curr) + n);
  check(curr - 1, "increment past end of ConstBlobPtr");
  return *this;
}

Blob::ConstBlobPtr &Blob::ConstBlobPtr::operator-=(difference_type n) {
  curr = static_cast<size_type>(static_cast<difference_type>(curr) - n);
  check(curr, "increment past end of ConstBlobPtr");
  return *this;
}

Blob::ConstBlobPtr Blob::ConstBlobPtr::operator+(difference_type n) const {
  ConstBlobPtr ret = *this;
  ret += n;
  return ret;
}

Blob::ConstBlobPtr Blob::ConstBlobPtr::operator-(difference_type n) const {
  ConstBlobPtr ret = *this;
  ret -= n;
  return ret;
}

Blob::ConstBlobPtr operator+(Blob::difference_type n,
                             const Blob::ConstBlobPtr &it) {
  return it + n;
}

Blob::ConstBlobPtr operator-(Blob::difference_type n,
                             const Blob::ConstBlobPtr &it) {
  return it - n;
}
