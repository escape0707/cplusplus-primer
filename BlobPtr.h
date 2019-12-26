#pragma once

#include <memory>
#include <string>
#include <vector>

#include "Blob.h"

template <typename T>
class Blob<T>::BlobPtr {
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

 public:
  friend bool operator==(const BlobPtr &lhs, const BlobPtr &rhs) {
    return lhs.curr == rhs.curr;
  }
  friend bool operator!=(const BlobPtr &lhs, const BlobPtr &rhs) {
    return !(lhs == rhs);
  }
  friend bool operator<(const BlobPtr &lhs, const BlobPtr &rhs) {
    return lhs.curr < rhs.curr;
  }
  friend bool operator>(const BlobPtr &lhs, const BlobPtr &rhs) {
    return rhs < lhs;
  }
  friend bool operator<=(const BlobPtr &lhs, const BlobPtr &rhs) {
    return !(lhs > rhs);
  }
  friend bool operator>=(const BlobPtr &lhs, const BlobPtr &rhs) {
    return !(lhs < rhs);
  }
  friend BlobPtr operator+(difference_type n, const BlobPtr &it) {
    return it + n;
  }
  friend BlobPtr operator-(difference_type n, const BlobPtr &it) {
    return it - n;
  }
};

#include "BlobPtr.tpp"
