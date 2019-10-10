#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;
using std::string;
using std::vector;

int &get(int *arry, int index) {
	return arry[index];
}

int main() {
	int ia[10];

	for (const int &elem: ia) {
		cout << elem << ' ';
	}
	cout << endl;

	for (int i = 0; i != 10; ++i) {
		get(ia, i) = i;
	}

	for (const int &elem : ia) {
		cout << elem << ' ';
	}
	cout << endl;
}
