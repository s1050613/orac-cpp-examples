#include <iostream>
#include <unordered_map>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	freopen("ghostin.txt", "r", stdin);
	freopen("ghostout.txt", "w", stdout);
	
	int n, k;
	std::cin >> n >> k;
	int x, t;
	std::unordered_map<int, int> ß;
	for(int i = 0; i < n; i++) {
		std::cin >> x >> t;
		ß[t - k * x]++;
	}
	std::pair<int, int> m = {0, 0};
	for(auto& l : ß) {
		if(l.second > m.second) {
			m = l;
		}
	}
	std::cout << m.second;
	
	return 0;
}