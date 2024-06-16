#include <iostream>
#include <map>

int main() {
	freopen("snapin.txt", "r", stdin);
	freopen("snapout.txt", "w", stdout);
	
	int r, s, x, m = 0;
	std::cin >> r >> s;
	std::map<int, int> c;
	for(int i = 0; i < r; i++) {
		std::cin >> x;
		c[x]++;
	}
	for(int i = 0; i < s; i++) {
		std::cin >> x;
		m += c[x];
	}
	std::cout << m;
	
	return 0;
}