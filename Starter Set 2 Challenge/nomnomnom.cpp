#include <iostream>

int main() {
	freopen("nomin.txt", "r", stdin);
	freopen("nomout.txt", "w", stdout);
	
	int n, x, f = 0, c = 0, s = 0;
	std::cin >> n;
	while(n--) {
		std::cin >> x;
		c += x;
		if(c >= f) {
			f = c;
			c = 0;
			s++;
		}
	}
	std::cout << s;
	
	return 0;
}