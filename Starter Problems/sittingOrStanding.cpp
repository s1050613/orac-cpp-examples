#include <iostream>

int main() {
	freopen("sitin.txt", "r", stdin);
	freopen("sitout.txt", "w", stdout);
	int r, s, t;
	std::cin >> r >> s >> t;
	int sitting = std::min(r * s, t);
	std::cout << sitting << " " << t - sitting;
	
	return 0;
}