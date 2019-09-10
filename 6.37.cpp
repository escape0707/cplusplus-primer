#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

string text[10] = {"H", "e", "l", "l", "o", "W", "o", "r", "l", "d"};

string (&func())[10] {
  return text;
}

using strArr = string[10];
strArr(&funcA()) {
  return text;
}

auto funcB() -> string (&)[10] {
  return text;
}

decltype(text) &funcC() {
  return text;
}

int main() {
  for (const auto &elem : func()) {
    cout << elem;
  }
  cout << endl;

  for (const auto &elem : funcA()) {
    cout << elem;
  }
  cout << endl;

  for (const auto &elem : funcB()) {
    cout << elem;
  }
  cout << endl;

  for (const auto &elem : funcC()) {
    cout << elem;
  }
  cout << endl;
}
