#pragma once

#include <memory>
#include <string>
#include <vector>

#include "Blob.h"

class ConstBlobPtr {
 public:
  using container_type = Blob::container_type;
  using size_type = Blob::size_type;
  using difference_type = Blob::difference_type;
  using const_reference = Blob::const_reference;
  using const_pointer = Blob::const_pointer;
  ConstBlobPtr();
  explicit ConstBlobPtr(const Blob &b, size_type sz = 0);
  const_reference operator*() const;
  const_pointer operator->() const;
  const_reference operator[](size_type pos) const;
  ConstBlobPtr &operator++();
  ConstBlobPtr operator++(int);
  ConstBlobPtr &operator+=(difference_type n);
  ConstBlobPtr operator+(difference_type n) const;
  ConstBlobPtr &operator--();
  ConstBlobPtr operator--(int);
  ConstBlobPtr &operator-=(difference_type n);
  ConstBlobPtr operator-(difference_type n) const;

 private:
  std::shared_ptr<container_type> check(size_type i,
                                        const std::string &msg) const;
  std::weak_ptr<container_type> wptr;
  size_type curr;
};

ConstBlobPtr operator+(ConstBlobPtr::difference_type n,
                          const ConstBlobPtr &it);
ConstBlobPtr operator-(ConstBlobPtr::difference_type n,
                          const ConstBlobPtr &it);
