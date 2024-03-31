#include <iostream>
#include <map>
 
int main() {
	freopen("dictin.txt", "r", stdin);
	freopen("dictout.txt", "w", stdout);
	
	int d, w, x, y;
	std::map<int, int> m;
	std::cin >> d >> w;
	for(int i = 0; i < d; i++) {
		std::cin >> x >> y;
		m[x] = y;
	}
	for(int i = 0; i < w; i++) {
		std::cin >> x;
		if(m.count(x) > 0) {
			std::cout << m[x] << std::endl;
		} else {
			std::cout << "C?" << std::endl;
		}
	}
	
	return 0;
}