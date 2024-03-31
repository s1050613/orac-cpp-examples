#include <iostream>
 
int main() {
	freopen("taktakin.txt", "r", stdin);
	freopen("taktakout.txt", "w", stdout);
	
	int f, i = 0;
	std::cin >> f;
	while((f - 1) % 11 > 0) {
		f *= 2;
		i++;
	}
	std::cout << i << " " << f;
	
	return 0;
}