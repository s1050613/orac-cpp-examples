#include <iostream>

int main() {
	freopen("genin.txt", "r", stdin);
	freopen("genout.txt", "w", stdout);
	
	int n, p, t = 0, m = 0, b;
	std::cin >> n >> p;
	int s[n];
	std::fill(s, s + n, 0);
	for(int i = 0;; i++) {
		s[i % n] += i + 1;
		t += i + 1;
		if(t >= p) {
			s[i % n] -= t - p;
			break;
		}
	}
	for(int i = 0; i < n; i++) {
		if(s[i] > m) {
			b = i + 1;
			m = s[i];
		}
	}
	std::cout << b << " " << m;
}