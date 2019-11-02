#ifndef STRBLOB_H
#define STRBLOB_H

#include <memory>
#include <string>
#include <vector>

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob {
  friend class StrBlobPtr;
  friend class ConstStrBlobPtr;

 public:
  // define types, see also std::stack
  using container_type = std::vector<std::string>;
  using value_type = container_type::value_type;
  using size_type = container_type::size_type;
  using reference = container_type::reference;
  using const_reference = container_type::const_reference;
  StrBlob();
  StrBlob(std::initializer_list<value_type> il);
  size_type size() const;
  bool empty() const;
  void push_back(const_reference value);
  void pop_back();
  const_reference front() const;
  reference front();
  const_reference back() const;
  reference back();
  StrBlobPtr begin();
  ConstStrBlobPtr cbegin() const;
  StrBlobPtr end();
  ConstStrBlobPtr cend() const;

 private:
  std::shared_ptr<container_type> data;
  void check(size_type i, const std::string &msg) const;
};

#endif
