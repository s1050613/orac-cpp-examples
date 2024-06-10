#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	freopen("cookiesin.txt", "r", stdin);
	freopen("cookiesout.txt", "w", stdout);
	
	int d, c0, p1, c1, p2, c2;
	std::cin >> d >> c0 >> p1 >> c1 >> p2 >> c2;
	
	int cookies = 0;
	bool bought1 = false, bought2 = false;
	int ogD = d, ogC0 = c0;
	while(d--) {
		// Strat 1 - buy factory 1 first
		cookies += c0;
		if(!bought1 && cookies >= p1 && d * c1 > p1) {
			c0 += c1;
			cookies -= p1;
			bought1 = true;
		}
		if(!bought2 && bought1 && cookies >= p2 && d * c2 > p2) {
			c0 += c2;
			cookies -= p2;
			bought2 = true;
		}
	}
	int s1cookies = cookies;
	cookies = 0;
	d = ogD;
	c0 = ogC0;
	bought1 = false;
	bought2 = false;
	while(d--) {
		// Strat 2 - buy factory 2 first
		cookies += c0;
		if(!bought2 && cookies >= p2 && d * c2 > p2) {
			c0 += c2;
			cookies -= p2;
			bought2 = true;
		}
		if(bought2 && !bought1 && cookies >= p1 && d * c1 > p1) {
			c0 += c1;
			cookies -= p1;
			bought1 = true;
		}
	}
	
	std::cout << std::max(cookies, s1cookies);
	
	return 0;
}