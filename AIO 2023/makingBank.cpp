#include <iostream>

int main() {
	freopen("bankin.txt", "r", stdin);
	freopen("bankout.txt", "w", stdout);
	
	int n, s = 1, m = 0;
	char c;
	std::cin >> n;
	while(n--) {
		std::cin >> c;
		if(c == 'C' && n > s) {
			s++;
		} else {
			m += s;
		}
	}
	std::cout << m;
	
	return 0;
}