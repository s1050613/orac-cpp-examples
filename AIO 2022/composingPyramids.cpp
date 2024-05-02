#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	freopen("compin.txt", "r", stdin);
	freopen("compout.txt", "w", stdout);
	
	int n;
	std::cin >> n;
	int p[n];
	int ascendingChains[100001]; // Lengths of chains ending on this note
	std::fill(ascendingChains, ascendingChains + 100001, 0);
	int longestAscendingChain[n];
	for(int i = 0; i < n; i++) {
		int note;
		std::cin >> note;
		p[i] = note;
		longestAscendingChain[i] = ascendingChains[note] = ascendingChains[note - 1] + 1;
	}
	
	int longestChain = 0;
	int descendingChains[100001]; // Lenghts of chains from this note
	std::fill(descendingChains, descendingChains + 100001, 0);
	int longestDescendingChain[n];
	for(int i = 0; i < n; i++) {
		int oppositeNote = p[n - i - 1];
		longestDescendingChain[i] = descendingChains[oppositeNote] = descendingChains[oppositeNote - 1] + 1;
	}
	for(int i = 0; i < n; i++) {
		longestChain = std::max(longestChain, std::min(longestAscendingChain[i], longestDescendingChain[n - i - 1]));
	}
	std::cout << n - 2 * longestChain + 1;
	
	return 0;
}