#include "Blob.h"

#include <memory>
#include <stdexcept>
#include <string>
#include <utility>

#include "BlobPtr.h"
#include "ConstBlobPtr.h"

Blob::Blob() : data(std::make_shared<container_type>()) {}

Blob::Blob(std::initializer_list<value_type> il)
    : data(std::make_shared<container_type>(il)) {}

Blob::Blob(const Blob &other)
    : data(std::make_shared<container_type>(*other.data)) {}

Blob &Blob::operator=(const Blob &rhs) {
  data = std::make_shared<container_type>(*rhs.data);
  return *this;
}

Blob::size_type Blob::size() const {
  return data->size();
}

bool Blob::empty() const {
  return data->empty();
}

void Blob::push_back(const_reference value) {
  data->push_back(value);
}

void Blob::check(size_type i, const std::string &msg) const {
  if (i >= data->size()) {
    throw std::out_of_range(msg);
  }
}

Blob::reference Blob::operator[](size_type pos) {
  return const_cast<reference>(std::as_const(*this)[pos]);
}

Blob::const_reference Blob::operator[](size_type pos) const {
  return (*data)[pos];
}

Blob::const_reference Blob::front() const {
  check(0, "front on empty Blob");
  return data->front();
}

Blob::reference Blob::front() {
  return const_cast<reference>(std::as_const(*this).front());
}

Blob::const_reference Blob::back() const {
  check(0, "back on empty Blob");
  return data->back();
}

Blob::reference Blob::back() {
  return const_cast<reference>(std::as_const(*this).back());
}

void Blob::pop_back() {
  check(0, "pop_back on empty Blob");
  data->pop_back();
}

Blob::BlobPtr Blob::begin() {
  return BlobPtr(*this);
}

Blob::ConstBlobPtr Blob::cbegin() const {
  return ConstBlobPtr(*this);
}

Blob::BlobPtr Blob::end() {
  return BlobPtr(*this, data->size());
}

Blob::ConstBlobPtr Blob::cend() const {
  return ConstBlobPtr(*this, data->size());
}

bool operator==(const Blob &lhs, const Blob &rhs) {
  return *lhs.data == *rhs.data;
}

bool operator!=(const Blob &lhs, const Blob &rhs) {
  return !(lhs == rhs);
}

bool operator<(const Blob &lhs, const Blob &rhs) {
  return *lhs.data < *rhs.data;
}

bool operator>(const Blob &lhs, const Blob &rhs) {
  return rhs < lhs;
}

bool operator<=(const Blob &lhs, const Blob &rhs) {
  return !(lhs > rhs);
}

bool operator>=(const Blob &lhs, const Blob &rhs) {
  return !(lhs < rhs);
}
