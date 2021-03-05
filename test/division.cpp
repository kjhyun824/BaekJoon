#include <iostream>
#include <iomanip>

int main() {
	double a, b;
	std::cin >> a >> b;
	std::cout << std::setprecision(9);
	std::cout << a / b << std::endl;
	return 0;
}
