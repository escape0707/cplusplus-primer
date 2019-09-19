#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

struct Person {
  Person(const std::string &n = "", const std::string &a = "")
      : name(n), address(a) {}
  std::string name, address;
};

std::istream &read(std::istream is, Person &person) {
  is >> person.name >> person.address;
}

std::ostream &print(std::ostream os, const Person &person) {
  os << person.name << person.address;
}

#endif
