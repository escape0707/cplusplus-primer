// see also StrBlob.h, StrVec.h & StrVec.cpp

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

#include "QueryResult.h"
#include "TextQuery.h"

using std::cin, std::cout, std::endl;
using std::ifstream;
using std::runtime_error;
using std::string;

// instantiate a TextQuery to query words and print the result
void runQueries(ifstream &fin) {
  TextQuery tq(fin);
  string s;
  do {
    cout << "enter word to look for, or q to quit: ";
    if (!(cin >> s) || s == "q") {
      break;
    }
    // query tq for s, and use the resulting QueryResult's print() method to
    // print the result
    tq.query(s).print() << endl;
  } while (true);
}

int main() {
  ifstream fin("a.in");
  if (!fin) {
    throw runtime_error("can't open input file");
  }

  runQueries(fin);
}
