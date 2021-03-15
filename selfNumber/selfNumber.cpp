#include <iostream>
using namespace std;

int counts[10001] = {0};

int dFunc(int n) {
	int temp = n;
	int output = n;

	while(temp != 0) {
		output += temp % 10;
		temp /= 10;
	}

	return output;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	for(int i = 1; i <= 10000; i++) {
		int temp = dFunc(i);
		if(temp <= 10000) counts[temp]++;
	}

	for(int i = 1; i <= 10000; i++) {
		if(counts[i] == 0) {
			cout << i << endl;
		}
	}

	return 0;
}
