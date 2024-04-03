#include <iostream>

int main() {
	freopen("cavalryin.txt", "r", stdin);
	freopen("cavalryout.txt", "w", stdout);
	
	int n, x;
	std::cin >> n;
	int a[n];
	std::fill(a, a + n, 0);
	for(int i = 0; i < n; i++) {
		std::cin >> x;
		a[x - 1]++;
	}
	for(int i = 0; i < n; i++) {
		if(a[i] % (i + 1)) {
			std::cout << "NO";
			return 0;
		}
	}
	std::cout << "YES";
	
	return 0;
}