#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for(int i = 0; i < T; i++) {
		string input;
		cin >> input;

		int sum = 0;
		int curr = 1;
		for(int i = 0 ; i < input.length(); i++) {
			if(input[i] == 'O') {
				sum += curr;
				curr += 1;
			} else {
				curr = 1;
			}
		}

		cout << sum << endl;
	}

	return 0;
}
