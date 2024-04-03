#include <iostream>
#include <map>

int main() {
	freopen("rafflein.txt", "r", stdin);
	freopen("raffleout.txt", "w", stdout);
	
	int n, k, x;
	std::map<int, int> m;
	std::cin >> n >> k;
	while(n--) {
		std::cin >> x;
		m[x]++;
	}
	for(auto& [num, freq] : m) {
		if(freq == 1) {
			std::cout << num;
			return 0;
		}
	}
	std::cout << -1;
	
	return 0;
}