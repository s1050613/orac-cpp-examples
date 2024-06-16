#include <iostream>

int main() {
	freopen("hailin.txt", "r", stdin);
	freopen("hailout.txt", "w", stdout);
	
	int x, s;
	std::cin >> x;
	while(x) {
		s = 0;
		while(x - 1) {
			if(x % 2) {
				x = 3 * x + 1;
			} else {
				x /= 2;
			}
			s++;
		}
		std::cout << s << std::endl;
		std::cin >> x;
	}
	
	return 0;
}