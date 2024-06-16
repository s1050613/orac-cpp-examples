#include <iostream>

int main() {
	freopen("fashin.txt", "r", stdin);
	freopen("fashout.txt", "w", stdout);
	
	int t, n = 0;
	int d[4] = {100, 20, 5, 1};
	std::cin >> t;
	for(int x : d) {
		while(t >= x) {
			t -= x;
			n++;
		}
	}
	std::cout << n;
	
	return 0;
}