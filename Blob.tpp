#include "Blob.h"

#include <memory>
#include <stdexcept>
#include <string>
#include <utility>

#include "BlobPtr.h"
#include "ConstBlobPtr.h"

using std::as_const;
using std::initializer_list, std::string;
using std::make_shared;
using std::out_of_range;

using value_type = Blob::value_type;
using size_type = Blob::size_type;
using reference = Blob::reference;
using const_reference = Blob::const_reference;

Blob::Blob() : data(make_shared<container_type>()) {}

Blob::Blob(initializer_list<value_type> il)
    : data(make_shared<container_type>(il)) {}

Blob::Blob(const Blob &other)
    : data(make_shared<container_type>(*other.data)) {}

Blob &Blob::operator=(const Blob &rhs) {
  data = make_shared<container_type>(*rhs.data);
  return *this;
}

size_type Blob::size() const {
  return data->size();
}

bool Blob::empty() const {
  return data->empty();
}

void Blob::push_back(const_reference value) {
  data->push_back(value);
}

void Blob::check(size_type i, const string &msg) const {
  if (i >= data->size()) {
    throw out_of_range(msg);
  }
}

reference Blob::operator[](size_type pos) {
  return const_cast<reference>(as_const(*this)[pos]);
}

const_reference Blob::operator[](size_type pos) const {
  return (*data)[pos];
}

const_reference Blob::front() const {
  check(0, "front on empty Blob");
  return data->front();
}

reference Blob::front() {
  return const_cast<reference>(as_const(*this).front());
}

const_reference Blob::back() const {
  check(0, "back on empty Blob");
  return data->back();
}

reference Blob::back() {
  return const_cast<reference>(as_const(*this).back());
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
