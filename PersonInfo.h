#ifndef PERSONINFO_H
#define PERSONINFO_H

#include <vector>
#include <string>
#include <ostream>

// members are public by default
struct PersonInfo {
  std::string name;
  std::vector<std::string> phones;
};

std::ostream &operator<<(std::ostream &os, const PersonInfo &info) {
  os << info.name << ':';
  for (const std::string &number : info.phones) {
    os << ' ' << number;
  }
  return os;
}

#endif