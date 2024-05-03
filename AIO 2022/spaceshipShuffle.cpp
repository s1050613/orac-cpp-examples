#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	freopen("spacein.txt", "r", stdin);
	freopen("spaceout.txt", "w", stdout);
	
	long long n, cost = 0;
	std::cin >> n;
	long long a[n];
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	long long x;
	long long totalPreviousExcess[n]; // Storing the accumulation of excess for previous cabins. This way, if one segment of the entire spaceship is 'solved' we effectively ignore it, since the excesses would have cancelled each other out.
	for(int i = 0; i < n; i++) {
		std::cin >> x;
		totalPreviousExcess[i] = (i? totalPreviousExcess[i - 1] : 0) + a[i] - x;
	}
	std::sort(totalPreviousExcess, totalPreviousExcess + n); // This has to be sorted to find the median element.
	long long mostNeutralCabin = totalPreviousExcess[(n - 1) / 2]; // This cabin has the least amount of change between the start and the end.
	for(int i = 0; i < n; i++) {
		cost += std::abs(mostNeutralCabin - totalPreviousExcess[i]); // By finding the difference between the most neutral cabin and each excess accumulation, we eliminate the possibility of going the long way around the spaceship - instead of the faster, more direct way.
	}
	std::cout << cost;
	
	return 0;
}