#pragma once

#include <memory>
#include <string>
#include <vector>

#include "StrVec.h"

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob {
  friend class StrBlobPtr;
  friend class ConstStrBlobPtr;
  friend bool operator==(const StrBlob &lhs, const StrBlob &rhs);
  friend bool operator<(const StrBlob &lhs, const StrBlob &rhs);

 public:
  // define types, see also std::stack
  using container_type = StrVec;
  using value_type = container_type::value_type;
  using size_type = container_type::size_type;
  using difference_type = container_type::difference_type;
  using reference = container_type::reference;
  using const_reference = container_type::const_reference;
  StrBlob();
  StrBlob(std::initializer_list<value_type> il);
  StrBlob(const StrBlob &other);
  StrBlob &operator=(const StrBlob &rhs);
  size_type size() const;
  bool empty() const;
  void push_back(const_reference value);
  void pop_back();
  const_reference front() const;
  reference front();
  const_reference back() const;
  reference back();
  const_reference index(size_type i) const;
  reference index(size_type i);
  reference operator[](size_type pos);
  const_reference operator[](size_type pos) const;
  StrBlobPtr begin();
  ConstStrBlobPtr cbegin() const;
  StrBlobPtr end();
  ConstStrBlobPtr cend() const;

 private:
  std::shared_ptr<container_type> data;
  void check(size_type i, const std::string &msg) const;
};

bool operator!=(const StrBlob &lhs, const StrBlob &rhs);
bool operator>(const StrBlob &lhs, const StrBlob &rhs);
bool operator<=(const StrBlob &lhs, const StrBlob &rhs);
bool operator>=(const StrBlob &lhs, const StrBlob &rhs);


#include "ConstStrBlobPtr.h"
#include "StrBlobPtr.h"
