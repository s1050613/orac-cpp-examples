#include <iostream>

int main() {
	freopen("piratein.txt", "r", stdin);
	freopen("pirateout.txt", "w", stdout);
	
	int l, x, y;
	std::cin >> l >> x >> y;
	std::cout << std::min(x + y, 2 * l - x - y);
	
	return 0;
}