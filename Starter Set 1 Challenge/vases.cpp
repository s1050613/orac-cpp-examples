#include <iostream>

int main() {
	freopen("vasesin.txt", "r", stdin);
	freopen("vasesout.txt", "w", stdout);
	
	int n;
	std::cin >> n;
	if(n < 6) {
		std::cout << "0 0 0";
	} else {
		std::cout << "1 2 " << n - 3;
	}
	
	return 0;
}