#include <iostream>
#include <cmath>

int main() {
	freopen("robotin.txt", "r", stdin);
	freopen("robotout.txt", "w", stdout);
	
	int n, x = 0, y = 0;
	char c;
	std::cin >> n;
	while(n--) {
		std::cin >> c;
		switch(c) {
			case 'N': y++; break;
			case 'E': x++; break;
			case 'S': y--; break;
			case 'W': x--; break;
		}
	}
	std::cout << std::abs(x) + std::abs(y);
	
	return 0;
}