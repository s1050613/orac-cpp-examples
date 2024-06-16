#include <iostream>

int main() {
	freopen("manin.txt", "r", stdin);
	freopen("manout.txt", "w", stdout);
	
	int ix, cx, id, cd;
	std::cin >> ix >> cx >> id >> cd;
	std::cout << ix + (ix + id == cx + cd || ix + id == cx - cd? id : -id);
	
	return 0;
}