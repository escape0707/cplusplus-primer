#pragma once

#include <memory>
#include <string>
#include <vector>

#include "Blob.h"

class Blob::BlobPtr {
 public:
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

Blob::BlobPtr operator+(Blob::difference_type n, const Blob::BlobPtr &it);
Blob::BlobPtr operator-(Blob::difference_type n, const Blob::BlobPtr &it);
