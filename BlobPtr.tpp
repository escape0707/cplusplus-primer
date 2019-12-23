#include <memory>
#include <stdexcept>
#include <string>

#include "Blob.h"
#include "BlobPtr.h"

using std::out_of_range, std::runtime_error;
using std::shared_ptr;
using std::string;

using container_type = BlobPtr::container_type;
using difference_type = BlobPtr::difference_type;
using reference = BlobPtr::reference;
using pointer = BlobPtr::pointer;

BlobPtr::BlobPtr() : curr(0) {}

BlobPtr::BlobPtr(Blob &b, size_type sz) : wptr(b.data), curr(sz) {}

shared_ptr<container_type> BlobPtr::check(size_type i,
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

reference BlobPtr::operator*() const {
  shared_ptr<container_type> p = check(curr, "dereference past end");
  return (*p)[curr];
}

pointer BlobPtr::operator->() const {
  return &**this;
}

reference BlobPtr::operator[](size_type pos) const {
  pos += curr;
  shared_ptr<container_type> p = check(pos, "dereference past end");
  return (*p)[pos];
}

BlobPtr &BlobPtr::operator++() {
  check(curr, "increment past end of BlobPtr");
  ++curr;
  return *this;
}

BlobPtr &BlobPtr::operator--() {
  --curr;
  check(curr, "decrement past begin of BlobPtr");
  return *this;
}

BlobPtr BlobPtr::operator++(int) {
  BlobPtr ret = *this;
  ++*this;
  return ret;
}

BlobPtr BlobPtr::operator--(int) {
  BlobPtr ret = *this;
  --*this;
  return ret;
}

BlobPtr &BlobPtr::operator+=(difference_type n) {
  curr = static_cast<size_type>(static_cast<difference_type>(curr) + n);
  check(curr - 1, "increment past end of BlobPtr");
  return *this;
}

BlobPtr &BlobPtr::operator-=(difference_type n) {
  curr = static_cast<size_type>(static_cast<difference_type>(curr) - n);
  check(curr, "increment past end of BlobPtr");
  return *this;
}

BlobPtr BlobPtr::operator+(difference_type n) const {
  BlobPtr ret = *this;
  ret += n;
  return ret;
}

BlobPtr BlobPtr::operator-(difference_type n) const {
  BlobPtr ret = *this;
  ret -= n;
  return ret;
}

BlobPtr operator+(difference_type n, const BlobPtr &it) {
  return it + n;
}

BlobPtr operator-(difference_type n, const BlobPtr &it) {
  return it - n;
}
