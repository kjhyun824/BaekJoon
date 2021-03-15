#include <iostream>
using namespace std;

bool isHan(int num) {
	if(num < 100) return true;
	if(num == 1000) return false;
	
	int hundred = num / 100, ten = (num / 10) % 10, one = num % 10;

	if(hundred - ten == ten - one) return true;
	else return false;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int target_num;
	cin >> target_num;

	int output = 0;

	for(int i = 1; i <= target_num; i++) {
		if(isHan(i)) output++;
	}

	cout << output << endl;

	return 0;
}
