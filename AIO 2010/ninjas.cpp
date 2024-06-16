#include <iostream>

int main() {
	freopen("ninjain.txt", "r", stdin);
	freopen("ninjaout.txt", "w", stdout);
	
	int n, k;
	std::cin >> n >> k;
	if(n > 0) {
		std::cout << n - 1 - (int)((n - 1) / (k + 1));
	} else {
		std::cout << 0;
	}
	
	return 0;
}