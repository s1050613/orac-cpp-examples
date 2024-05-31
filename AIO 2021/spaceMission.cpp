#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
 
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	freopen("spacein.txt", "r", stdin);
	freopen("spaceout.txt", "w", stdout);
	
	int n, f;
	std::cin >> n >> f;
	int c[n];
	int runningMin = INT_MAX;
	std::vector<std::pair<int, int>> goodLefts, goodRights;
	// For each day, if there is an earlier day with lower fuel cost, it will be a better starting day.
	// So, we only keep track of the days which have nothing lower earlier than them - if they do, they won't be optimal.
	for(int i = 0; i < n; i++) {
		std::cin >> c[i];
		if(c[i] < runningMin) {
			goodLefts.push_back({c[i], i});
			runningMin = c[i];
		}
	}
	
	// Same idea: Only keep track of the days with nothing less than them later for the return days.
	runningMin = INT_MAX;
	for(int i = n - 1; i >= 0; i--) {
		if(c[i] < runningMin) {
			goodRights.push_back({c[i], i});
			runningMin = c[i];
		}
	}
	
	// By now, we have 2 vectors: goodLefts containing a descending list of optimal days for landing, and goodRights containing an ascending list of optimal days for returning.
	// For both vectors, each item contains the fuel cost and index.
	// now we just use two pointers to find the furthest-apart pair which fits in the fuel constraint.
	std::reverse(goodRights.begin(), goodRights.end());
	int leftI = 0, rightI = 0;
	int longestDistance = -1;
	int rightStart = 0;
	int leftSize = goodLefts.size(), rightSize = goodRights.size();
	
	while(true) {
		std::pair<int, int> leftDay = goodLefts[leftI];
		std::pair<int, int> rightDay = goodRights[rightI];
		if(leftDay.first + rightDay.first <= f) {
			longestDistance = std::max(longestDistance, rightDay.second - leftDay.second + 1);
			if(++rightI == rightSize) break;
		} else {
			if(++leftI == leftSize) break;
		}
	}
	// Distance of 1 means we start and end on the last day, which is impossible
	if(longestDistance == 1) {
		longestDistance = -1;
	}
	std::cout << longestDistance;
	
	return 0;
}