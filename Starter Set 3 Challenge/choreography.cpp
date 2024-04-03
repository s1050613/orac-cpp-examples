#include <iostream>

int main() {
	freopen("dancein.txt", "r", stdin);
	freopen("danceout.txt", "w", stdout);
	
	int d, t, a, b, r = 0;
	std::cin >> d >> t;
	int h[++d];
	std::fill(h, h + d, 0);
	while(t--) {
		std::cin >> a >> b;
		if(h[a]) {
			h[a]--;
		} else {
			r++;
		}
		h[b]++;
	}
	std::cout << r;
	
	return 0;
}