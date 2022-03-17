#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> vec = { 1, 2, 3, 4 };

//1
	int sum = 0;
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] % 2 == 0) {
			sum = sum + vec[i];
		}
	}
	cout << "sum of even elements in vec = " << sum << endl;

//2
	int sum2 = 0;
	for (int i = 0; i < vec.size(); i++) {
		if (i % 2 == 0) {
			sum2 = sum2 + vec[i];
		}
	}
	cout << "sum of elements with even indices in vec = " << sum2 << endl;

	return 0;
}