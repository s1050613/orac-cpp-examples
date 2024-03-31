#include <iostream>
 
int main() {
	freopen("rainin.txt", "r", stdin);
	freopen("rainout.txt", "w", stdout);
	
	int n, c, x, s = 0;
	std::cin >> n >> c;
	for(int i = 1; i <= n; i++) {
		std::cin >> x;
		s += x;
		if(s >= c) {
			std::cout << i;
			break;
		}
	}
	
	return 0;
}