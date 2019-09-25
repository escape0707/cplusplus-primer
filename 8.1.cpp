#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::istream;
using std::string;
using std::vector;

istream &process_input(istream &is) {
  cout << is.rdbuf();  // write everything in is buffer into cout

  // ignore everything still in is's buffer, then reset is's rdstate().
  // note that the ignore() below won't set failbit even if EOF is reached.
  // after all, it succeeded to "ignore until and including EOF".
  // and istream's bool operator (invoked when use istream object as bool)
  // returns !fail(), which is true when rdstate() equals goodbit or eofbit
  is.ignore(std::numeric_limits<std::streamsize>::max());
  if (is) {
    is.clear();
  }

  // if the correct rdstate is needed, maybe it's ok and convenient to invoke
  // .peek() immediately after .ignore()

  return is;  // return is stream
}

int main() {
  int i;
  cin >> i;
  process_input(cin);
  if (cin) {
    cout << i << endl;
  }
}
