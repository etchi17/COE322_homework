#include <iostream>
using namespace std;

void swap(int &a, int &b) {
	int c;
	c = a;
	a = b;
	b = c;
}

int main() {
	int i = 1;
	int j = 2;

	cout << i << ", " << j << endl;
	swap(i, j);
	cout << i << ", " << j << endl;

	return 0;
}

