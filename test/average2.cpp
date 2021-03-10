#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for(int i = 0; i < T; i++) {
		int num;
		cin >> num;

		double scores[num];
		double sum = 0.0;
		for(int i = 0; i < num; i++) {
			cin >> scores[i];
			sum += scores[i];
		}

		double average = sum / (double) num;

		int count = 0;
		for(int i = 0; i < num; i++) {
			if(scores[i] > average) count++;
		}

		cout << fixed << setprecision(3);
		cout << ((double) count / (double) (num) * 100.0) << "%" << endl;
	}

	return 0;
}
