#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int main() {
	string s;
	while (string::iterator iter != s.end()) { /* ... */
	}                                          // no initialization for iter
	while (bool status = find(word)) {         /* ... */
	}
	if (!status) { /* ... */
	}              // out of scope
}
