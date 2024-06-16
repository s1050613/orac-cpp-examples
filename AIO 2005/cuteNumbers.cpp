#include <iostream>

int main() {
	freopen("cutein.txt", "r", stdin);
	freopen("cuteout.txt", "w", stdout);
	
	int n, x, c = 0;
	std::cin >> n;
	while(n--) {
		std::cin >> x;
		if(!x) {
			c++;
		} else {
			c = 0;
		}
	}
	std::cout << c;
	
	return 0;
}