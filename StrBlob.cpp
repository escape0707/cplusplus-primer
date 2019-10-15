#include <stdexcept>
#include <memory>
#include <string>
#include <utility>
#include <vector>

using std::as_const;
using std::initializer_list, std::string;
using std::make_shared, std::shared_ptr;
using std::out_of_range;
using std::vector;

#include "StrBlob.h"

StrBlob::StrBlob() : data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il)
    : data(make_shared<vector<string>>(il)) {}

void StrBlob::check(size_type i, const string &msg) const {
  if (i >= data->size()) {
    throw out_of_range(msg);
  }
}

const string &StrBlob::front() const {
  check(0, "front on empty StrBlob");
  return data->front();
}

string &StrBlob::front() {
  return const_cast<string &>(as_const(*this).front());
}

const string &StrBlob::back() const {
  check(0, "back on empty StrBlob");
  return data->back();
}

string &StrBlob::back() {
  return const_cast<string &>(as_const(*this).back());
}

void StrBlob::pop_back() {
  check(0, "pop_back on empty StrBlob");
  data->pop_back();
}
string &StrBlob::back() {
  check(0, "back on empty StrBlob");
  return data->back();
}
void StrBlob::pop_back() {
  check(0, "pop_back on empty StrBlob");
  data->pop_back();
}