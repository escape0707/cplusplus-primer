#include <memory>
#include <stdexcept>
#include <string>

#include "StrBlob.h"
#include "StrBlobPtr.h"

using std::out_of_range, std::runtime_error;
using std::shared_ptr;
using std::string;

using container_type = StrBlobPtr::container_type;
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

StrBlobPtr &StrBlobPtr::incr() {
  check(curr, "increment past end of StrBlobPtr");
  ++curr;
  return *this;
}
