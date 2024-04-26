#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	freopen("groundin.txt", "r", stdin);
	freopen("groundout.txt", "w", stdout);
	
	int n, h = 0, s, c = -1, x;
	std::cin >> n;
	while(n--) {
		std::cin >> x;
		if(x != c) {
			c = x;
			s = 1;
		}
		h = std::max(h, s++ * c);
	}
	std::cout << h;
	
	return 0;
}