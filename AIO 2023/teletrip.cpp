#include <iostream>
#include <set>

int main() {
	freopen("telein.txt", "r", stdin);
	freopen("teleout.txt", "w", stdout);
	
	int n, x = 0;
	char d;
	std::set<int> p = {0};
	std::cin >> n;
	while(n--) {
		std::cin >> d;
		switch(d) {
			case 'L': x--; break;
			case 'R': x++; break;
			case 'T': x = 0; break;
		}
		p.insert(x);
	}
	std::cout << p.size();
	
	return 0;
}