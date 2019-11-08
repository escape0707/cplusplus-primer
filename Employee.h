#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <cstddef>
#include <string>

class Employee {
 public:
  Employee() : id(++count) {}
  Employee(const std::string &name) : name(name), id(++count) {}

 private:
  inline static std::size_t count = 0;
  std::string name;
  std::size_t id;
};

#endif
