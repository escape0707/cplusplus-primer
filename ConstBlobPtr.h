#pragma once

#include <memory>
#include <string>
#include <vector>

#include "Blob.h"

template <typename T>
class Blob<T>::ConstBlobPtr {
 public:
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

 public:
  friend bool operator==(const ConstBlobPtr &lhs, const ConstBlobPtr &rhs) {
    return lhs.curr == rhs.curr;
  }
  friend bool operator!=(const ConstBlobPtr &lhs, const ConstBlobPtr &rhs) {
    return !(lhs == rhs);
  }
  friend bool operator<(const ConstBlobPtr &lhs, const ConstBlobPtr &rhs) {
    return lhs.curr < rhs.curr;
  }
  friend bool operator>(const ConstBlobPtr &lhs, const ConstBlobPtr &rhs) {
    return rhs < lhs;
  }
  friend bool operator<=(const ConstBlobPtr &lhs, const ConstBlobPtr &rhs) {
    return !(lhs > rhs);
  }
  friend bool operator>=(const ConstBlobPtr &lhs, const ConstBlobPtr &rhs) {
    return !(lhs < rhs);
  }
  friend ConstBlobPtr operator+(difference_type n, const ConstBlobPtr &it) {
    return it + n;
  }
  friend ConstBlobPtr operator-(difference_type n, const ConstBlobPtr &it) {
    return it - n;
  }
};

#include "ConstBlobPtr.tpp"
