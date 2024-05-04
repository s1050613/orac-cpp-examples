#include <iostream>
#include <algorithm>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	freopen("distin.txt", "r", stdin);
	freopen("distout.txt", "w", stdout);
	
	int n, k;
	std::cin >> n >> k;
	int d[n];
	for(int i = 0; i < n; i++) {
		std::cin >> d[i];
	}
	std::sort(d, d + n);
	int h = 0, l;
	for(int i = 0; i < n; i++) {
		int pos = d[i];
		if(!i || pos >= l + k) {
			h++;
			l = pos;
		}
	}
	std::cout << h;
	
	return 0;
}