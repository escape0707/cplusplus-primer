#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int main() {
	int v1 = 0, v2 = 1;
	swap(v1, v2);
	cout << v1 << ' ' << v2 << endl;

	swap(v1, v2);
	cout << v1 << ' ' << v2 << endl;

	return 0;
}
