#pragma once

#include <memory>
#include <string>
#include <vector>

#include "StrBlob.h"

class StrBlobPtr {
 public:
  using container_type = StrBlob::container_type;
  using size_type = StrBlob::size_type;
  using reference = StrBlob::reference;
  StrBlobPtr();
  StrBlobPtr(StrBlob &b, size_type sz = 0);
  reference deref() const;
  reference operator[](size_type pos) const;
  StrBlobPtr &incr();

 private:
  std::shared_ptr<container_type> check(size_type i,
                                        const std::string &msg) const;
  std::weak_ptr<container_type> wptr;
  size_type curr;
};
