#include <fstream>
#include <iostream>
#include <iterator>
#include <string>

using std::cout, std::endl;
using std::ifstream;
using std::istream_iterator;
using std::string;


int main() {
  ifstream fin("a.in");
  if (!fin) {
    return -1;
  }

  const string ascender("bdfhijklt"), descender("gjpqy"),
      a_d(ascender + descender);

  string longest;
  int max = 0;

  // for each word in file fin
  for (istream_iterator<string> curr(fin); curr != istream_iterator<string>();
       ++curr) {
    // if the word contains neither ascenders nor descenders
    if (curr->find_first_of(a_d) == string::npos) {
      // ... and it's longer, then record the word along with its length
      if (curr->length() > max) {
        max = curr->length();
        longest = *curr;
      }
    }
  }

  cout << "Longest: " << longest << endl;
  cout << "Length: " << max << endl;
}