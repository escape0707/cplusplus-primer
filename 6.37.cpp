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
strArr &funcA() {
  return text;
}

auto funcB() -> string (&)[10] {
  return text;
}

decltype(text) &funcC() {
  return text;
}

int main() {
  for (const string &elem : func()) {
    cout << elem;
  }
  cout << endl;

  for (const string &elem : funcA()) {
    cout << elem;
  }
  cout << endl;

  for (const string &elem : funcB()) {
    cout << elem;
  }
  cout << endl;

  for (const string &elem : funcC()) {
    cout << elem;
  }
  cout << endl;
}
