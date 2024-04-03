#include <iostream>
#include <cmath>

int main() {
	freopen("streetin.txt", "r", stdin);
	freopen("streetout.txt", "w", stdout);
	
	int n, k;
	std::cin >> n >> k;
	std::cout << n / (k + 1);
	
	return 0;
}