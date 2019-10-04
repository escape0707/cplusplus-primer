#include <string>

using std::string;

void surround(string &s, const string &prefix, const string &suffix) {
  s.insert(s.cbegin(), prefix.cbegin(), prefix.cend());
  s.append(suffix);
}
