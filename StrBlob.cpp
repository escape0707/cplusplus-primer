#include <memory>
#include <stdexcept>
#include <string>
#include <utility>

#include "ConstStrBlobPtr.h"
#include "StrBlob.h"
#include "StrBlobPtr.h"

using std::as_const;
using std::initializer_list, std::string;
using std::make_shared;
using std::out_of_range;

using value_type = StrBlob::value_type;
using size_type = StrBlob::size_type;
using reference = StrBlob::reference;
using const_reference = StrBlob::const_reference;

StrBlob::StrBlob() : data(make_shared<container_type>()) {}

StrBlob::StrBlob(initializer_list<value_type> il)
    : data(make_shared<container_type>(il)) {}

size_type StrBlob::size() const {
  return data->size();
}

bool StrBlob::empty() const {
  return data->empty();
}

void StrBlob::push_back(const_reference value) {
  data->push_back(value);
}

void StrBlob::check(size_type i, const string &msg) const {
  if (i >= data->size()) {
    throw out_of_range(msg);
  }
}

const_reference StrBlob::front() const {
  check(0, "front on empty StrBlob");
  return data->front();
}

reference StrBlob::front() {
  return const_cast<reference>(as_const(*this).front());
}

const_reference StrBlob::back() const {
  check(0, "back on empty StrBlob");
  return data->back();
}

reference StrBlob::back() {
  return const_cast<reference>(as_const(*this).back());
}

void StrBlob::pop_back() {
  check(0, "pop_back on empty StrBlob");
  data->pop_back();
}

const_reference StrBlob::index(size_type i) const {
  return (*data)[i];
}

reference StrBlob::index(size_type i) {
  return const_cast<reference>(as_const(*this).index(i));
}

StrBlobPtr StrBlob::begin() {
  return StrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::cbegin() const {
  return ConstStrBlobPtr(*this);
}

StrBlobPtr StrBlob::end() {
  return StrBlobPtr(*this, data->size());
}

ConstStrBlobPtr StrBlob::cend() const {
  return ConstStrBlobPtr(*this, data->size());
}
