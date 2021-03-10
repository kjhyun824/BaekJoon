#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	double score[T];
	double max = 0.0;

	for(int i = 0; i < T; i++) {
		cin >> score[i];
		if(score[i] > max) max = score[i];
	}

	double sum = 0.0;

	for(int i = 0; i < T; i++) {
		sum += score[i] / max * 100.0;
	}

	cout << sum / (double) T << endl;

	return 0;
}
