#include <iostream>
using namespace std;

int main() {
	int maxCount = 0;

	for (int i = 1; i <= 1000; i++) {
		int j = i;
		int count = 1;

		while (j != 1) {
			count++;

			if (j % 2 == 0) {
				j = j / 2;
			}
			else {
				j = 3*j + 1;
			}
		}

		if (count > maxCount) {
			maxCount = count;
			cout << i << endl;
		}
	}

	return 0;
}