#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>

#include "StrBlob.h"
#include "StrBlobPtr.h"

using std::cout, std::endl;
using std::getline, std::string;
using std::ifstream;
using std::runtime_error;

int main() {
  ifstream fin("a.in");
  if (!fin) {
    throw runtime_error("can't open input file");
  }

  StrBlob text;
  for (string s; getline(fin, s);) {
    text.push_back(std::move(s));  // Todo: better forward StrBlob::push_back()
  }

  StrBlobPtr p(text);
  for (StrBlobPtr::size_type i = 0, sz = text.size(); i != sz; ++i) {
    cout << p.deref() << endl;
    p.incr();
  }
}
