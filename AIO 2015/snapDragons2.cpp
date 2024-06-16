#include <iostream>

int main() {
	freopen("snapin.txt", "r", stdin);
	freopen("snapout.txt", "w", stdout);
	
	int r, c, rr, rc, sr, sc;
	std::cin >> r >> c >> rr >> rc >> sr >> sc;
	std::cout << ((rr - sr + rc - sc) % 2 == 0? "SCARLET" : "ROSE");
	
	return 0;
}