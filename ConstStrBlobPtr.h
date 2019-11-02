#ifndef CONSTSTRBLOBPTR_H
#define CONSTSTRBLOBPTR_H

#include <memory>
#include <string>
#include <vector>

#include "StrBlob.h"

class ConstStrBlobPtr {
 public:
  using container_type = StrBlob::container_type;
  using size_type = StrBlob::size_type;
  using const_reference = StrBlob::const_reference;
  ConstStrBlobPtr();
  ConstStrBlobPtr(const StrBlob &b, size_type sz = 0);
  const_reference deref() const;
  ConstStrBlobPtr &incr();

 private:
  std::shared_ptr<container_type> check(size_type i,
                                        const std::string &msg) const;
  std::weak_ptr<container_type> wptr;
  size_type curr;
};

#endif
