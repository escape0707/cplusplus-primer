#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Person {
  friend std::istream &read(std::istream &is, Person &person);
  friend std::ostream &print(std::ostream &os, const Person &person);

 public:
  Person(const std::string &n = "", const std::string &a = "")
      : name(n), address(a) {}

 private:
  std::string name, address;
};

inline std::istream &read(std::istream &is, Person &person) {
  return is >> person.name >> person.address;
}

inline std::ostream &print(std::ostream &os, const Person &person) {
  return os << person.name << person.address;
}

#endif
