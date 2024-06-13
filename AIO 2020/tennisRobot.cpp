#include <iostream>
#include <vector>
#include <algorithm>

int mod(int a, int b) {
	return (a % b + b) % b;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	freopen("tennisin.txt", "r", stdin);
	freopen("tennisout.txt", "w", stdout);
	
	int b, n, a;
	std::cin >> b >> n;
	std::vector<std::pair<int, int>> bins; // <bin capacity, bin index>
	for(int i = 0; i < b; i++) {
		std::cin >> a;
		bins.push_back({a, i + 1});
	}
	std::sort(bins.begin(), bins.end());
	
	int currentBinLevel = 0;
	int fullBins = 0;
	int remainingBins = b;
	int lowestBinCapacity = -1;
	while(n > 0) {
		while(lowestBinCapacity > -1 && bins[fullBins].first == lowestBinCapacity) {
			fullBins++;
			remainingBins--;
		}
		
		lowestBinCapacity = bins[fullBins].first;
		int levelsToAdd = lowestBinCapacity - currentBinLevel;
		
		n -= remainingBins * levelsToAdd;
		currentBinLevel = lowestBinCapacity;
	}
	std::sort(bins.begin() + fullBins, bins.end(), [](std::pair<int, int> &a, std::pair<int, int> &b) {
		return a.second < b.second;
	});
	
	int currentBin = mod(n - 1, remainingBins);
	std::cout << bins[fullBins + currentBin].second;
	
	return 0;
}