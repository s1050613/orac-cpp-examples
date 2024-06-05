#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	freopen("laserin.txt", "r", stdin);
	freopen("laserout.txt", "w", stdout);
	
	int n;
	std::string a, b;
	std::cin >> n >> a >> b;
	int size = 0, maxSize = 0;
	for(int i = 0; i < n * 2; i++) {
		// The largest square will grow only if both paths allow it, and shrink if both paths require it to.
		if(a[i] == 'D' && b[i] == 'R') {
			size++;
		} else if(a[i] == 'R' && b[i] == 'D') {
			size--;
		}
		if(size > maxSize) {
			maxSize = size;
		} 
	}
	std::cout << maxSize;
	
	return 0;
}