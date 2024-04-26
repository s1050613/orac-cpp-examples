#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	freopen("elecin.txt", "r", stdin);
	freopen("elecout.txt", "w", stdout);
	
	int n;
	std::cin >> n;
	int votes[3] = {0, 0, 0};
	char c;
	while(n--) {
		std::cin >> c;
		votes[c - 'A']++;
	}
	if(votes[0] > std::max(votes[1], votes[2])) {
		std::cout << 'A';
	} else if(votes[1] > std::max(votes[0], votes[2])) {
		std::cout << 'B';
	} else if(votes[2] > std::max(votes[0], votes[1])) {
		std::cout << 'C';
	} else {
		std::cout << 'T';
	}
	return 0;
}