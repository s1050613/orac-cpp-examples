#include <iostream>
 
int main() {
	freopen("encyin.txt", "r", stdin);
	freopen("encyout.txt", "w", stdout);
	
	int n, q, x;
	std::cin >> n >> q;
	int p[n];
	for(int i = 0; i < n; i++) {
		std::cin >> p[i];
	}
	for(int i = 0; i < q; i++) {
		std::cin >> x;
		std::cout << p[x - 1] << std::endl;;
	}
	
	return 0;
}