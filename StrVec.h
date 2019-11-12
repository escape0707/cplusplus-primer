#pragma once

#include <cstddef>
#include <memory>
#include <string>
#include <utility>

class StrVec {
 public:
  using value_type = std::string;
  using allocator_type = std::allocator<value_type>;
  using size_type = std::size_t;
  using difference_type = std::ptrdiff_t;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = value_type *;
  using const_iterator = const value_type *;
  StrVec();
  StrVec(const StrVec &other);
  StrVec(std::initializer_list<value_type> il);
  StrVec &operator=(const StrVec &rhs);
  ~StrVec();
  void push_back(const_reference value);
  void pop_back();
  void resize(size_type count);
  void resize(size_type count, const_reference value);
  bool empty() const;
  size_type size() const;
  void reserve(size_type new_cap);
  size_type capacity() const;
  reference operator[](size_type pos);
  const_reference operator[](size_type pos) const;
  reference front();
  const_reference front() const;
  reference back();
  const_reference back() const;
  iterator begin();
  const_iterator begin() const;
  const_iterator cbegin() const;
  iterator end();
  const_iterator end() const;
  const_iterator cend() const;

 private:
  using Alloc_traits = std::allocator_traits<allocator_type>;
  inline static allocator_type alloc;
  static iterator allocate(size_type n);
  static std::pair<iterator, iterator> alloc_n_copy(const_iterator beg,
                                                    const_iterator end);
  static std::pair<iterator, iterator> alloc_n_move(iterator beg, iterator end);
  void _pop_back_n(size_type n);
  void _reserve(size_type new_cap);
  void chk_n_alloc();
  void free();
  iterator elements = nullptr;
  iterator first_free = nullptr;
  iterator cap = nullptr;
};
