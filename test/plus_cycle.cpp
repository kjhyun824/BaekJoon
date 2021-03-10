#include <iostream>
using namespace std;

int main() {
	int start, target, count = 0;
	cin >> start;

	target = start;

	do {
		count++;
		int ones = target % 10;
		int tens = target / 10;
		target = ones * 10 + ((ones + tens) % 10);
	} while(start != target);

	cout << count << endl;
	return 0;
}
