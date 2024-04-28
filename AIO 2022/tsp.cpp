#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	freopen("tspin.txt", "r", stdin);
	freopen("tspout.txt", "w", stdout);
	
	int n;
	std::cin >> n;
	int l[n], r[n];
	for(int i = 0; i < n; i++) {
		std::cin >> l[i];
	}
	int x = -1;
	for(int i = 0; i < n; i++) {
		std::cin >> r[i];
		if(l[i] > x) {
			x = l[i];
		} else if(r[i] < x) {
			std::cout << "NO";
			return 0;
		}
	}
	std::cout << "YES";
	return 0;
}