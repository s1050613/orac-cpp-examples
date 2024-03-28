#include <iostream>
#include <cmath>

int main() {
	freopen("mixin.txt", "r", stdin);
	freopen("mixout.txt", "w", stdout);
	int n, d;
	std::cin >> n >> d;
	int a = std::floor(n / d);
	std::cout << a;
	if(a * d != n) {
		std::cout << " " << n - a * d << "/" << d;
	}
	
	return 0;
}