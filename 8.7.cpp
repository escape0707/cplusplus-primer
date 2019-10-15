#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "Sales_data.h"

using std::cerr;
using std::cin, std::cout, std::endl;
using std::ifstream, std::ofstream;
using std::string;
using std::vector;

int main(int argc, char *argv[]) {
  ifstream fin(argv[1]);
  ofstream fout(argv[2]);
  if (!fin) {
    throw std::invalid_argument("Can't open input file.");
  }
  if (!fout) {
    throw std::invalid_argument("Can't open output file.");
  }

  Sales_data total;        // variable to hold the running sum
  if (read(fin, total)) {  // read the first transaction
    Sales_data trans;      // variable to hold data for the next transaction
    while (read(fin, trans)) {             // read the remaining transactions
      if (total.isbn() == trans.isbn()) {  // check the isbns
        total.combine(trans);              // update the running total
      } else {
        print(fout, total) << endl;  // print the results
        total = trans;               // process the next book
      }
    }
    print(fout, total) << endl;   // print the last transaction
  } else {                        // there was no input
    cerr << "No data?!" << endl;  // notify the user
  }
}
