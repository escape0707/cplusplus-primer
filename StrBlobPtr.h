#pragma once

#include <memory>
#include <string>
#include <vector>

#include "StrBlob.h"

class StrBlobPtr {
 public:
  using container_type = StrBlob::container_type;
  using size_type = StrBlob::size_type;
  using difference_type = StrBlob::difference_type;
  using reference = StrBlob::reference;
  using pointer = StrBlob::pointer;
  StrBlobPtr();
  explicit StrBlobPtr(StrBlob &b, size_type sz = 0);
  reference operator*() const;
  pointer operator->() const;
  reference operator[](size_type pos) const;
  StrBlobPtr &operator++();
  StrBlobPtr operator++(int);
  StrBlobPtr &operator+=(difference_type n);
  StrBlobPtr operator+(difference_type n) const;
  StrBlobPtr &operator--();
  StrBlobPtr operator--(int);
  StrBlobPtr &operator-=(difference_type n);
  StrBlobPtr operator-(difference_type n) const;

 private:
  std::shared_ptr<container_type> check(size_type i,
                                        const std::string &msg) const;
  std::weak_ptr<container_type> wptr;
  size_type curr;
};

StrBlobPtr operator+(StrBlobPtr::difference_type n, StrBlobPtr it);
StrBlobPtr operator-(StrBlobPtr::difference_type n, StrBlobPtr it);
