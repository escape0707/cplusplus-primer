#pragma once

#include <cstddef>
#include <memory>

class numbered {
 public:
  numbered() : mysn(++count) {}
  numbered(const numbered &other) : numbered(){};  //
  std::size_t mysn;

 private:
  inline static std::size_t count = 0;
};
