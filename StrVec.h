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
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = value_type *;
  using const_iterator = const value_type *;
  StrVec();
  StrVec(const StrVec &other);
  StrVec &operator=(const StrVec &rhs);
  ~StrVec();
  void push_back(const_reference value);
  void resize(size_type count);
  void resize(size_type count, const_reference value);
  size_type size() const;
  void reserve(size_type new_cap);
  size_type capacity() const;
  iterator begin() const;
  iterator end() const;

 private:
  using Alloc_traits = std::allocator_traits<allocator_type>;
  inline static allocator_type alloc;
  static iterator allocate(size_type n);
  static std::pair<iterator, iterator> alloc_n_copy(const_iterator beg,
                                                    const_iterator end);
  static std::pair<iterator, iterator> alloc_n_move(iterator beg, iterator end);
  void chk_n_alloc();
  void free();
  void reallocate();
  iterator elements = nullptr;
  iterator first_free = nullptr;
  iterator cap = nullptr;
};
