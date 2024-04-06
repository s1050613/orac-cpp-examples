#include <iostream>
 
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	freopen("shopin.txt", "r", stdin);
	freopen("shopout.txt", "w", stdout);
	
	int n, m, b;
	std::cin >> n >> m;
	int h[n], s[m], p[m], r[n];
	for(int i = 0; i < n; i++) {
		std::cin >> h[i];
	}
	for(int i = 0; i < m; i++) {
		std::cin >> s[i];
	}
	for(int i = 0; i < m; i++) {
		std::cin >> p[i];
	}
	
	if(s[m - 1] <= h[0]) { // All supermarkets are left of the houses
		b = p[0] - s[0];
		for(int shopI = 1; shopI < m; shopI++) {
			b = std::min(b, p[shopI] - s[shopI]);
		}
		for(int houseI = 0; houseI < n; houseI++) {
			std::cout << b + h[houseI] << " ";
		}
	} else if(s[0] >= h[n - 1]) { // All supermarkets are right of the houses
		b = p[0] + s[0];
		for(int shopI = 1; shopI < m; shopI++) {
			b = std::min(b, p[shopI] + s[shopI]);
		}
		for(int houseI = 0; houseI < n; houseI++) {
			std::cout << b - h[houseI] << " ";
		}
	} else {
		int leftScores[m], rightScores[m];
		for(int i = 0; i < m; i++) {
			leftScores[i] = p[i] - s[i];
			rightScores[i] = p[i] + s[i];
		}
		int leftMinimum[m] = {leftScores[0]}, rightMinimum[m];
		for(int i = 1; i < m; i++) {
			leftMinimum[i] = std::min(leftScores[i], leftMinimum[i - 1]);
		}
		rightMinimum[m - 1] = rightScores[m - 1];
		for(int i = m - 2; i >= 0; i--) {
			rightMinimum[i] = std::min(rightScores[i], rightMinimum[i + 1]);
		}
		int closestRightShop[n];
		int ri = 0;
		for(int i = 0; i < n; i++) {
			while(s[ri] < h[i] && ri < m) {
				ri++; // Continue incrementing index of closest right shop until the shop is to the right of the house
			}
			closestRightShop[i] = ri;
		}
		for(int i = 0; i < n; i++) {
			int rs = closestRightShop[i];
			if(rs && rs < m) {
				std::cout << std::min(leftMinimum[rs - 1] + h[i], rightMinimum[rs] - h[i]) << " ";
			} else if(rs) {
				std::cout << leftMinimum[rs - 1] + h[i] << " ";
			} else if(rs < m) {
				std::cout << rightMinimum[rs] - h[i] << " ";
			}
		}
	}
	
	return 0;
}