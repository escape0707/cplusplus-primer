#pragma once

#include <memory>
#include <stdexcept>
#include <string>

#include "Blob.h"
#include "BlobPtr.h"

template <typename T>
Blob<T>::BlobPtr::BlobPtr() : curr(0) {}

template <typename T>
Blob<T>::BlobPtr::BlobPtr(Blob &b, size_type sz) : wptr(b.data), curr(sz) {}

template <typename T>
std::shared_ptr<typename Blob<T>::container_type> Blob<T>::BlobPtr::check(
    size_type i,
    const std::string &msg) const {
  std::shared_ptr<container_type> ret = wptr.lock();
  if (!ret) {
    throw std::runtime_error("unbound BlobPtr");
  }
  if (i >= ret->size()) {
    throw std::out_of_range(msg);
  }
  return ret;
}

template <typename T>
typename Blob<T>::reference Blob<T>::BlobPtr::operator*() const {
  std::shared_ptr<container_type> p = check(curr, "dereference past end");
  return (*p)[curr];
}

template <typename T>
typename Blob<T>::pointer Blob<T>::BlobPtr::operator->() const {
  return &**this;
}

template <typename T>
typename Blob<T>::reference Blob<T>::BlobPtr::operator[](size_type pos) const {
  pos += curr;
  std::shared_ptr<container_type> p = check(pos, "dereference past end");
  return (*p)[pos];
}

template <typename T>
typename Blob<T>::BlobPtr &Blob<T>::BlobPtr::operator++() {
  check(curr, "increment past end of BlobPtr");
  ++curr;
  return *this;
}

template <typename T>
typename Blob<T>::BlobPtr &Blob<T>::BlobPtr::operator--() {
  --curr;
  check(curr, "decrement past begin of BlobPtr");
  return *this;
}

template <typename T>
typename Blob<T>::BlobPtr Blob<T>::BlobPtr::operator++(int) {
  BlobPtr ret = *this;
  ++*this;
  return ret;
}

template <typename T>
typename Blob<T>::BlobPtr Blob<T>::BlobPtr::operator--(int) {
  BlobPtr ret = *this;
  --*this;
  return ret;
}

template <typename T>
typename Blob<T>::BlobPtr &Blob<T>::BlobPtr::operator+=(difference_type n) {
  curr = static_cast<size_type>(static_cast<difference_type>(curr) + n);
  check(curr - 1, "increment past end of BlobPtr");
  return *this;
}

template <typename T>
typename Blob<T>::BlobPtr &Blob<T>::BlobPtr::operator-=(difference_type n) {
  curr = static_cast<size_type>(static_cast<difference_type>(curr) - n);
  check(curr, "increment past end of BlobPtr");
  return *this;
}

template <typename T>
typename Blob<T>::BlobPtr Blob<T>::BlobPtr::operator+(difference_type n) const {
  BlobPtr ret = *this;
  ret += n;
  return ret;
}

template <typename T>
typename Blob<T>::BlobPtr Blob<T>::BlobPtr::operator-(difference_type n) const {
  BlobPtr ret = *this;
  ret -= n;
  return ret;
}
