#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int counts[10];

	for(int i = 0; i < 10; i++) counts[i] = 0;

	int a, b, c;
	cin >> a >> b >> c;
	int target = a * b * c;

	while(target != 0) {
		int temp = target % 10;
		counts[temp] += 1;
		target /= 10;
	}

	for(int i = 0; i < 10; i++) cout << counts[i] << "\n";
}
