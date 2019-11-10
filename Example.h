#pragma once

#include <vector>

class Example {
 public:
  static inline double rate = 6.5;
  static constexpr int vecSize = 20;
  static std::vector<double> vec;
};

std::vector<double> Example::vec(vecSize);
