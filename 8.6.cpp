#include <exception>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Sales_data.h"

using std::cerr;
using std::cin, std::cout, std::endl;
using std::ifstream;
using std::string;
using std::vector;

int main(int argc, char *argv[]) {
  ifstream fin(argv[1]);
  if (!fin) {
    throw std::invalid_argument("Can't open input file.");
  }

  Sales_data total;        // variable to hold the running sum
  if (read(fin, total)) {  // read the first transaction
    Sales_data trans;      // variable to hold data for the next transaction
    while (read(fin, trans)) {             // read the remaining transactions
      if (total.isbn() == trans.isbn()) {  // check the isbns
        total.combine(trans);              // update the running total
      } else {
        print(cout, total) << endl;  // print the results
        total = trans;               // process the next book
      }
    }
    print(cout, total) << endl;   // print the last transaction
  } else {                        // there was no input
    cerr << "No data?!" << endl;  // notify the user
  }
}
