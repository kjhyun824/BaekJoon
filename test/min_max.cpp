#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T  = 9;
	int idx, max = 0;
	

	for(int i = 0; i < T; i++) {
		int temp;
		cin >> temp;

		if(temp > max) {
			max = temp;
			idx = i + 1;
		}
	}

	cout << max << endl;
	cout << idx << endl;

	return 0;
}
