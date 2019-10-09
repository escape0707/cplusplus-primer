#include <iostream>
#include <string>

using std::cout, std::endl;
using std::string;

int main() {
  string s("ab2c3d7R4E6");
  string num("0123456789");
  string alpha("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");

  for (string::size_type pos = 0;
       pos = s.find_first_of(num, pos), pos != string::npos; ++pos) {
    cout << s[pos];
  }
  cout << endl;

  for (string::size_type pos = 0;
       pos = s.find_first_of(alpha, pos), pos != string::npos; ++pos) {
    cout << s[pos];
  }
  cout << endl;

  for (string::size_type pos = 0;
       pos = s.find_first_not_of(alpha, pos), pos != string::npos; ++pos) {
    cout << s[pos];
  }
  cout << endl;

  for (string::size_type pos = 0;
       pos = s.find_first_not_of(num, pos), pos != string::npos; ++pos) {
    cout << s[pos];
  }
  cout << endl;
}