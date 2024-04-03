#include <iostream>
#include <limits>

#define INT_MIN std::numeric_limits<int>::min()
#define INT_MAX std::numeric_limits<int>::max()

int main() {
	freopen("ladyin.txt", "r", stdin);
	freopen("ladyout.txt", "w", stdout);
	
	int n, x, min = INT_MAX, max = INT_MIN;
	std::cin >> n;
	while(n--) {
		std::cin >> x;
		min = std::min(min, x);
		max = std::max(max, x);
	}
	std::cout << max - min + 1;
	
	return 0;
}