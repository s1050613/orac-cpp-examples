#include <iostream>
#include <limits>

#define INT_MIN std::numeric_limits<int>::min()
#define INT_MAX std::numeric_limits<int>::max()

int main() {
	freopen("artin.txt", "r", stdin);
	freopen("artout.txt", "w", stdout);
	
	int n, x, y, minX = INT_MAX, maxX = INT_MIN, minY = INT_MAX, maxY = INT_MIN;
	std::cin >> n;
	while(n--) {
		std::cin >> x >> y;
		minX = std::min(minX, x);
		maxX = std::max(maxX, x);
		minY = std::min(minY, y);
		maxY = std::max(maxY, y);
	}
	std::cout << (maxX - minX) * (maxY - minY);
	
	return 0;
}