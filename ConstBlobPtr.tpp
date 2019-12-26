#pragma once

#include <memory>
#include <stdexcept>
#include <string>

#include "Blob.h"
#include "ConstBlobPtr.h"

template <typename T>
Blob<T>::ConstBlobPtr::ConstBlobPtr() : curr(0) {}

template <typename T>
Blob<T>::ConstBlobPtr::ConstBlobPtr(const Blob<T> &b, size_type sz)
    : wptr(b.data), curr(sz) {}

template <typename T>
std::shared_ptr<typename Blob<T>::container_type> Blob<T>::ConstBlobPtr::check(
    size_type i,
    const std::string &msg) const {
  std::shared_ptr<container_type> ret = wptr.lock();
  if (!ret) {
    throw std::runtime_error("unbound ConstBlobPtr");
  }
  if (i >= ret->size()) {
    throw std::out_of_range(msg);
  }
  return ret;
}

template <typename T>
typename Blob<T>::const_reference Blob<T>::ConstBlobPtr::operator*() const {
  std::shared_ptr<container_type> p = check(curr, "dereference past end");
  return (*p)[curr];
}

template <typename T>
typename Blob<T>::const_pointer Blob<T>::ConstBlobPtr::operator->() const {
  return &**this;
}

template <typename T>
typename Blob<T>::const_reference Blob<T>::ConstBlobPtr::operator[](
    size_type pos) const {
  pos += curr;
  std::shared_ptr<container_type> p = check(pos, "dereference past end");
  return (*p)[pos];
}

template <typename T>
typename Blob<T>::ConstBlobPtr &Blob<T>::ConstBlobPtr::operator++() {
  check(curr, "increment past end of ConstBlobPtr");
  ++curr;
  return *this;
}

template <typename T>
typename Blob<T>::ConstBlobPtr &Blob<T>::ConstBlobPtr::operator--() {
  --curr;
  check(curr, "decrement past begin of ConstBlobPtr");
  return *this;
}

template <typename T>
typename Blob<T>::ConstBlobPtr Blob<T>::ConstBlobPtr::operator++(int) {
  ConstBlobPtr ret = *this;
  ++*this;
  return ret;
}

template <typename T>
typename Blob<T>::ConstBlobPtr Blob<T>::ConstBlobPtr::operator--(int) {
  ConstBlobPtr ret = *this;
  --*this;
  return ret;
}

template <typename T>
typename Blob<T>::ConstBlobPtr &Blob<T>::ConstBlobPtr::operator+=(
    difference_type n) {
  curr = static_cast<size_type>(static_cast<difference_type>(curr) + n);
  check(curr - 1, "increment past end of ConstBlobPtr");
  return *this;
}

template <typename T>
typename Blob<T>::ConstBlobPtr &Blob<T>::ConstBlobPtr::operator-=(
    difference_type n) {
  curr = static_cast<size_type>(static_cast<difference_type>(curr) - n);
  check(curr, "increment past end of ConstBlobPtr");
  return *this;
}

template <typename T>
typename Blob<T>::ConstBlobPtr Blob<T>::ConstBlobPtr::operator+(
    difference_type n) const {
  ConstBlobPtr ret = *this;
  ret += n;
  return ret;
}

template <typename T>
typename Blob<T>::ConstBlobPtr Blob<T>::ConstBlobPtr::operator-(
    difference_type n) const {
  ConstBlobPtr ret = *this;
  ret -= n;
  return ret;
}
