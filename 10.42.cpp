#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <string>

using std::copy;
using std::cout, std::endl;
using std::list;
using std::ostream_iterator;
using std::string;

template <typename T>
void elimDups(list<T> &slst) {
  slst.sort();
  slst.unique();
}

int main() {
  list<string> words{"the",  "quick", "red",  "fox", "jumps",
                     "over", "the",   "slow", "red", "turtle"};
  elimDups(words);
  copy(words.cbegin(), words.cend(), ostream_iterator<string>(cout, " "));
  cout << endl;
}