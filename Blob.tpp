#pragma once

#include <memory>
#include <stdexcept>
#include <string>
#include <utility>

#include "Blob.h"
#include "BlobPtr.h"
#include "ConstBlobPtr.h"

template <typename T>
Blob<T>::Blob() : data(std::make_shared<container_type>()) {}

template <typename T>
Blob<T>::Blob(std::initializer_list<value_type> il)
    : data(std::make_shared<container_type>(il)) {}

template <typename T>
Blob<T>::Blob(const Blob &other)
    : data(std::make_shared<container_type>(*other.data)) {}

template <typename T>
Blob<T> &Blob<T>::operator=(const Blob &rhs) {
  data = std::make_shared<container_type>(*rhs.data);
  return *this;
}

template <typename T>
typename Blob<T>::size_type Blob<T>::size() const {
  return data->size();
}

template <typename T>
bool Blob<T>::empty() const {
  return data->empty();
}

template <typename T>
void Blob<T>::push_back(const_reference value) {
  data->push_back(value);
}

template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const {
  if (i >= data->size()) {
    throw std::out_of_range(msg);
  }
}

template <typename T>
typename Blob<T>::reference Blob<T>::operator[](size_type pos) {
  return const_cast<reference>(std::as_const(*this)[pos]);
}

template <typename T>
typename Blob<T>::const_reference Blob<T>::operator[](size_type pos) const {
  return (*data)[pos];
}

template <typename T>
typename Blob<T>::const_reference Blob<T>::front() const {
  check(0, "front on empty Blob");
  return data->front();
}

template <typename T>
typename Blob<T>::reference Blob<T>::front() {
  return const_cast<reference>(std::as_const(*this).front());
}

template <typename T>
typename Blob<T>::const_reference Blob<T>::back() const {
  check(0, "back on empty Blob");
  return data->back();
}

template <typename T>
typename Blob<T>::reference Blob<T>::back() {
  return const_cast<reference>(std::as_const(*this).back());
}

template <typename T>
void Blob<T>::pop_back() {
  check(0, "pop_back on empty Blob");
  data->pop_back();
}

template <typename T>
typename Blob<T>::BlobPtr Blob<T>::begin() {
  return BlobPtr(*this);
}

template <typename T>
typename Blob<T>::ConstBlobPtr Blob<T>::cbegin() const {
  return ConstBlobPtr(*this);
}

template <typename T>
typename Blob<T>::BlobPtr Blob<T>::end() {
  return BlobPtr(*this, data->size());
}

template <typename T>
typename Blob<T>::ConstBlobPtr Blob<T>::cend() const {
  return ConstBlobPtr(*this, data->size());
}

template <typename T>
bool operator==(const Blob<T> &lhs, const Blob<T> &rhs) {
  return *lhs.data == *rhs.data;
}

template <typename T>
bool operator!=(const Blob<T> &lhs, const Blob<T> &rhs) {
  return !(lhs == rhs);
}

template <typename T>
bool operator<(const Blob<T> &lhs, const Blob<T> &rhs) {
  return *lhs.data < *rhs.data;
}

template <typename T>
bool operator>(const Blob<T> &lhs, const Blob<T> &rhs) {
  return rhs < lhs;
}

template <typename T>
bool operator<=(const Blob<T> &lhs, const Blob<T> &rhs) {
  return !(lhs > rhs);
}

template <typename T>
bool operator>=(const Blob<T> &lhs, const Blob<T> &rhs) {
  return !(lhs < rhs);
}
