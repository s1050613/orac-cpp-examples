#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	freopen("buildin.txt", "r", stdin);
	freopen("buildout.txt", "w", stdout);
	
	int n, u = 0;
	std::cin >> n;
	int h[n], d[n - 1];
	for(int i = 0; i < n; i++) {
		std::cin >> h[i];
		if(i) {
			d[i - 1] = std::abs(h[i] - h[i - 1]);
			u += d[i - 1];
		}
	}
	int bestSavings = 0;
	for(int i = 0; i < n; i++) {
		if(i == 0) {
			bestSavings = std::max(bestSavings, d[0]);
		} else if(i == n - 1) {
			bestSavings = std::max(bestSavings, d[n - 2]);
		} else {
			int highestNeighbour = std::max(h[i - 1], h[i + 1]);
			int lowestNeighbour = std::min(h[i - 1], h[i + 1]);
			if(h[i] > highestNeighbour) { // If it is higher than both neighbours
				bestSavings = std::max(bestSavings, 2 * (h[i] - highestNeighbour));
			} else if(h[i] < lowestNeighbour) { // If it is lower than both neighbours
				bestSavings = std::max(bestSavings, 2 * (lowestNeighbour - h[i]));
			}
		}
	}
	std::cout << u - bestSavings;
	
	return 0;
}