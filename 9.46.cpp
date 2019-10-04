#include <string>

using std::string;

void surround(string &s, const string &prefix, const string &suffix) {
  s.insert(0, prefix);
  s.insert(s.length(), suffix);
}