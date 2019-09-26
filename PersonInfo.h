#ifndef PERSONINFO_H
#define PERSONINFO_H

#include <vector>
#include <string>
#include <ostream>

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
  return true;
}

const PersonInfo::number_type &format(const PersonInfo::number_type &number) {
  return number;
}

#endif