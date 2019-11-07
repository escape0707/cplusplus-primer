#ifndef NUMBERED_H
#define NUMBERED_H

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

#endif
