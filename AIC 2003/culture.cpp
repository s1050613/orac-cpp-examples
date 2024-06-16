#include <iostream>

int main() {
	freopen("cultin.txt", "r", stdin);
	freopen("cultout.txt", "w", stdout);
	
	int n, d = 0;
	std::cin >> n;
	while(n % 2 == 0) {
		d++;
		n /= 2;
	}
	std::cout << n << " " << d;
	
	return 0;
}