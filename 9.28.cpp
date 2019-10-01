#include <forward_list>
#include <iostream>
#include <string>

using std::cout, std::endl, std::cerr;
using std::forward_list;
using std::ostream;
using std::string;

forward_list<string>::const_iterator find(const forward_list<string> &sflist,
                                          const string &str) {
  auto prev = sflist.cbefore_begin();
  for (auto curr = sflist.cbegin(); curr != sflist.cend(); prev = curr++) {
    if (*curr == str) {
      return curr;
    }
  }
  return prev;  // which is sflist.cend()-1;
}

void insert_after(forward_list<string> &sflist,
                  const string &dest,
                  string &&src) {
  sflist.insert_after(find(sflist, dest), std::move(src));
  cerr << "move" << endl;
}

void insert_after(forward_list<string> &sflist,
                  const string &dest,
                  const string &src) {
  sflist.emplace_after(find(sflist, dest), src);
  cerr << "construct" << endl;
}

ostream &operator<<(ostream &os, const forward_list<string> &text) {
  for (const auto &elem : text) {
    os << elem << ' ';
  }
  return os;
}

int main() {
  forward_list<string> text1{"Hello", "world!"};

  insert_after(text1, "Hello", "to the");
  cout << text1 << endl;

  string s("Bob!");
  insert_after(text1, "Hi!", s);
  cout << text1 << endl;
}