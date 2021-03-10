#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	bool appear[42] = {false};
	int count = 0;

	for(int i = 0; i < 10; i++) {
		int temp;
		cin >> temp;

		if(!appear[temp % 42]) {
			count ++;
			appear[temp % 42] = true;
		}

	}

	cout << count << endl;
	return 0;
}
