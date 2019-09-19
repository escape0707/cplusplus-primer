#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

struct Person {
  std::string name, address;
};

std::istream &read(std::istream is, Person &person) {
  is >> person.name >> person.address;
}

std::ostream &print(std::ostream os, const Person &person) {
  os << person.name << person.address;
}

#endif
