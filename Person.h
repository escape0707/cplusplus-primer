#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Person {
  friend std::istream &read(std::istream is, Person &person);
  friend std::ostream &print(std::ostream os, const Person &person);

 public:
  Person(const std::string &n = "", const std::string &a = "")
      : name(n), address(a) {}

 private:
  std::string name, address;
};

std::istream &read(std::istream is, Person &person) {
  is >> person.name >> person.address;
}

std::ostream &print(std::ostream os, const Person &person) {
  os << person.name << person.address;
}

#endif
