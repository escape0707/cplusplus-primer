#pragma once

#include <cstddef>
#include <memory>
#include <string>
#include <utility>

template <typename T>
class Vec {
 public:
  using value_type = T;
  using allocator_type = std::allocator<value_type>;

 private:
  using Alloc_traits = std::allocator_traits<allocator_type>;

 public:
  using size_type = std::size_t;
  using difference_type = std::ptrdiff_t;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = value_type *;
  using const_iterator = const value_type *;
  using pointer = typename Alloc_traits::pointer;
  using const_pointer = typename Alloc_traits::const_pointer;
  Vec();
  template <typename InputIt>
  Vec(const InputIt &first, const InputIt &last);
  Vec(const Vec &other);
  Vec(Vec &&other) noexcept;
  Vec(std::initializer_list<value_type> il);
  Vec &operator=(const Vec &rhs);
  Vec &operator=(Vec &&rhs) noexcept;
  Vec &operator=(std::initializer_list<value_type> il);
  ~Vec();
  void push_back(const_reference value);
  void push_back(value_type &&value);
  void pop_back();
  void resize(size_type new_size);
  void resize(size_type new_size, const_reference value);
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
  inline static allocator_type alloc;
  static iterator allocate(size_type n);
  static std::pair<iterator, iterator> alloc_n_copy(const_iterator beg,
                                                    const_iterator end);
  void destroy_starting_from(iterator pos);
  void _reserve(size_type new_cap);
  void chk_n_alloc();
  void free();
  iterator elements = nullptr;
  iterator first_free = nullptr;
  iterator cap = nullptr;
};

template <typename T>
bool operator==(const Vec<T> &lhs, const Vec<T> &rhs);
template <typename T>
bool operator!=(const Vec<T> &lhs, const Vec<T> &rhs);
template <typename T>
bool operator<(const Vec<T> &lhs, const Vec<T> &rhs);
template <typename T>
bool operator>(const Vec<T> &lhs, const Vec<T> &rhs);
template <typename T>
bool operator<=(const Vec<T> &lhs, const Vec<T> &rhs);
template <typename T>
bool operator>=(const Vec<T> &lhs, const Vec<T> &rhs);

#include "Vec.tpp"
