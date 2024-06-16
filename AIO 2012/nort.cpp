#include <iostream>

int main() {
	freopen("nortin.txt", "r", stdin);
	freopen("nortout.txt", "w", stdout);
	
	int w, h;
	std::cin >> w >> h;
	std::cout << 2 * (w * h / 2);
	
	return 0;
}