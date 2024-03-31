#include <iostream>
 
int main() {
	freopen("dishin.txt", "r", stdin);
	freopen("dishout.txt", "w", stdout);
	
	int n, x, min, max, sum = 0;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> x;
		sum += x;
		if(i == 0) {
			min = x;
			max = x;
		} else {
			min = std::min(min, x);
			max = std::max(max, x);
		}
	}
	std::cout << min << " " << max << " " << sum / n;
	
	return 0;
}