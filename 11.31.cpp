#include <iostream>
#include <map>
#include <string>
#include <utility>

using std::cout, std::endl, std::ostream;
using std::multimap;
using std::pair;
using std::string;

template <typename Key, typename T, typename K>
typename multimap<Key, T>::iterator find_erase(multimap<Key, T> &m,
                                               const K &value) {
  typename multimap<Key, T>::iterator pos = m.find(value);
  if (pos == m.cend()) {
    return pos;
  }
  return m.erase(pos);
}

template <typename Key, typename T, typename K>
typename multimap<Key, T>::const_iterator find_erase(const multimap<Key, T> &m,
                                                     const K &value) {
  return find_erase(const_cast<multimap<Key, T>>(m), value);
}

template <typename T1, typename T2>
ostream &operator<<(ostream &os, pair<T1, T2> p) {
  return os << p.first << ": " << p.second;
}

template <typename Key, typename T>
ostream &operator<<(ostream &os, multimap<Key, T> m) {
  for (const pair<const Key, T> p : m) {
    os << p << endl;
  }
  return os;
}

int main() {
  multimap<string, string> authors = {{"A", "B"}, {"Andy", "Book"}};
  cout << authors << endl;
  find_erase(authors, "A");
  cout << authors << endl;
  find_erase(authors, "B");
  cout << authors << endl;
}