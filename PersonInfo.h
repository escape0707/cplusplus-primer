#pragma once

#include <ostream>
#include <regex>
#include <string>
#include <vector>

// members are public by default
struct PersonInfo {
  std::string name;
  using number_type = std::string;
  std::vector<number_type> phones;
};

std::ostream &operator<<(std::ostream &os, const PersonInfo &info) {
  os << info.name << ':';
  for (const std::string &number : info.phones) {
    os << ' ' << number;
  }
  return os;
}

bool valid(const PersonInfo::number_type &number) {
  std::regex r("(\\())?\\d{3}(\\))?([-. ])?\\d{3}([-. ])?\\d{4}");
  std::smatch m;
  if (std::regex_match(number, m, r)) {
    if (m[1].matched) {
      return m[2].matched && (!m[3].matched || m[3].str() == " ");
    } else {
      return !m[2].matched && m[3].str() == m[4].str();
    }
  }
  return false;
}

const PersonInfo::number_type &format(const PersonInfo::number_type &number) {
  return number;
}
