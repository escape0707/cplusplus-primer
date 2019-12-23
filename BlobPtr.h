#pragma once

#include <memory>
#include <string>
#include <vector>

#include "Blob.h"

class BlobPtr {
 public:
  using container_type = Blob::container_type;
  using size_type = Blob::size_type;
  using difference_type = Blob::difference_type;
  using reference = Blob::reference;
  using pointer = Blob::pointer;
  BlobPtr();
  explicit BlobPtr(Blob &b, size_type sz = 0);
  reference operator*() const;
  pointer operator->() const;
  reference operator[](size_type pos) const;
  BlobPtr &operator++();
  BlobPtr operator++(int);
  BlobPtr &operator+=(difference_type n);
  BlobPtr operator+(difference_type n) const;
  BlobPtr &operator--();
  BlobPtr operator--(int);
  BlobPtr &operator-=(difference_type n);
  BlobPtr operator-(difference_type n) const;

 private:
  std::shared_ptr<container_type> check(size_type i,
                                        const std::string &msg) const;
  std::weak_ptr<container_type> wptr;
  size_type curr;
};

BlobPtr operator+(BlobPtr::difference_type n, const BlobPtr &it);
BlobPtr operator-(BlobPtr::difference_type n, const BlobPtr &it);
