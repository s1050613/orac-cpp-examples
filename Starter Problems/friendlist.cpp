#include <iostream>
 
int main() {
	freopen("listin.txt", "r", stdin);
	freopen("listout.txt", "w", stdout);
	
	int f, a, b;
	std::cin >> f;
	int p[1001]; // Sorry
	std::fill(p, p + 1001, 0);
	for(int i = 0; i < f; i++) {
		std::cin >> a >> b;
		p[a]++;
		p[b]++;
	}
	int h = 0;
	for(int i = 0; i < 1001; i++) {
		h = std::max(h, p[i]);
	}
	for(int i = 0; i < 1001; i++) {
		if(p[i] == h) {
			std::cout << i << std::endl;
		}
	}
	
	return 0;
}