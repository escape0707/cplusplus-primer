#include <memory>
#include <stdexcept>
#include <string>

#include "Blob.h"
#include "BlobPtr.h"

using std::out_of_range, std::runtime_error;
using std::shared_ptr;
using std::string;

Blob::BlobPtr::BlobPtr() : curr(0) {}

Blob::BlobPtr::BlobPtr(Blob &b, size_type sz) : wptr(b.data), curr(sz) {}

shared_ptr<Blob::container_type> Blob::BlobPtr::check(size_type i,
                                                      const string &msg) const {
  shared_ptr<container_type> ret = wptr.lock();
  if (!ret) {
    throw runtime_error("unbound BlobPtr");
  }
  if (i >= ret->size()) {
    throw out_of_range(msg);
  }
  return ret;
}

Blob::reference Blob::BlobPtr::operator*() const {
  shared_ptr<container_type> p = check(curr, "dereference past end");
  return (*p)[curr];
}

Blob::pointer Blob::BlobPtr::operator->() const {
  return &**this;
}

Blob::reference Blob::BlobPtr::operator[](size_type pos) const {
  pos += curr;
  shared_ptr<container_type> p = check(pos, "dereference past end");
  return (*p)[pos];
}

Blob::BlobPtr &Blob::BlobPtr::operator++() {
  check(curr, "increment past end of BlobPtr");
  ++curr;
  return *this;
}

Blob::BlobPtr &Blob::BlobPtr::operator--() {
  --curr;
  check(curr, "decrement past begin of BlobPtr");
  return *this;
}

Blob::BlobPtr Blob::BlobPtr::operator++(int) {
  BlobPtr ret = *this;
  ++*this;
  return ret;
}

Blob::BlobPtr Blob::BlobPtr::operator--(int) {
  BlobPtr ret = *this;
  --*this;
  return ret;
}

Blob::BlobPtr &Blob::BlobPtr::operator+=(difference_type n) {
  curr = static_cast<size_type>(static_cast<difference_type>(curr) + n);
  check(curr - 1, "increment past end of BlobPtr");
  return *this;
}

Blob::BlobPtr &Blob::BlobPtr::operator-=(difference_type n) {
  curr = static_cast<size_type>(static_cast<difference_type>(curr) - n);
  check(curr, "increment past end of BlobPtr");
  return *this;
}

Blob::BlobPtr Blob::BlobPtr::operator+(difference_type n) const {
  BlobPtr ret = *this;
  ret += n;
  return ret;
}

Blob::BlobPtr Blob::BlobPtr::operator-(difference_type n) const {
  BlobPtr ret = *this;
  ret -= n;
  return ret;
}

Blob::BlobPtr operator+(Blob::difference_type n, const Blob::BlobPtr &it) {
  return it + n;
}

Blob::BlobPtr operator-(Blob::difference_type n, const Blob::BlobPtr &it) {
  return it - n;
}
