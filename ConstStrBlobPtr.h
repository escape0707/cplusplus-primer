#pragma once

#include <memory>
#include <string>
#include <vector>

#include "StrBlob.h"

class ConstStrBlobPtr {
 public:
  using container_type = StrBlob::container_type;
  using size_type = StrBlob::size_type;
  using difference_type = StrBlob::difference_type;
  using const_reference = StrBlob::const_reference;
  ConstStrBlobPtr();
  ConstStrBlobPtr(const StrBlob &b, size_type sz = 0);
  const_reference deref() const;
  const_reference operator[](size_type pos) const;
  ConstStrBlobPtr &operator++();
  ConstStrBlobPtr operator++(int);
  ConstStrBlobPtr &operator+=(difference_type n);
  ConstStrBlobPtr operator+(difference_type n) const;
  ConstStrBlobPtr &operator--();
  ConstStrBlobPtr operator--(int);
  ConstStrBlobPtr &operator-=(difference_type n);
  ConstStrBlobPtr operator-(difference_type n) const;

 private:
  std::shared_ptr<container_type> check(size_type i,
                                        const std::string &msg) const;
  std::weak_ptr<container_type> wptr;
  size_type curr;
};

ConstStrBlobPtr operator+(ConstStrBlobPtr::difference_type n,
                          ConstStrBlobPtr it);
ConstStrBlobPtr operator-(ConstStrBlobPtr::difference_type n,
                          ConstStrBlobPtr it);
