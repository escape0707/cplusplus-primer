#pragma once

#include <memory>
#include <string>
#include <vector>

#include "Vec.h"

template <typename T>
class Blob;
template <typename T>
bool operator==(const Blob<T> &lhs, const Blob<T> &rhs);
template <typename T>
bool operator<(const Blob<T> &lhs, const Blob<T> &rhs);

template <typename T>
class Blob {
  friend bool operator== <>(const Blob &lhs, const Blob &rhs);
  friend bool operator< <>(const Blob &lhs, const Blob &rhs);

 public:
  class BlobPtr;
  class ConstBlobPtr;
  // define types, see also std::stack
  using container_type = Vec<T>;
  using value_type = typename container_type::value_type;
  using size_type = typename container_type::size_type;
  using difference_type = typename container_type::difference_type;
  using reference = typename container_type::reference;
  using const_reference = typename container_type::const_reference;
  using pointer = typename container_type::pointer;
  using const_pointer = typename container_type::const_pointer;
  Blob();
  Blob(std::initializer_list<value_type> il);
  Blob(const Blob &other);
  Blob &operator=(const Blob &rhs);
  size_type size() const;
  bool empty() const;
  void push_back(const_reference value);
  void pop_back();
  const_reference front() const;
  reference front();
  const_reference back() const;
  reference back();
  reference operator[](size_type pos);
  const_reference operator[](size_type pos) const;
  BlobPtr begin();
  ConstBlobPtr cbegin() const;
  BlobPtr end();
  ConstBlobPtr cend() const;

 private:
  std::shared_ptr<container_type> data;
  void check(size_type i, const std::string &msg) const;
};

template <typename T>
bool operator!=(const Blob<T> &lhs, const Blob<T> &rhs);
template <typename T>
bool operator>(const Blob<T> &lhs, const Blob<T> &rhs);
template <typename T>
bool operator<=(const Blob<T> &lhs, const Blob<T> &rhs);
template <typename T>
bool operator>=(const Blob<T> &lhs, const Blob<T> &rhs);

#include "Blob.tpp"
