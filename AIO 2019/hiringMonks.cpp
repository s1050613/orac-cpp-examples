#include <iostream>
#include <algorithm>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	freopen("hirein.txt", "r", stdin);
	freopen("hireout.txt", "w", stdout);
	
	int N, S, M;
	std::cin >> N;
	int x[N];
	for(int i = 0; i < N; i++) {
		std::cin >> x[i];
	}
	
	std::cin >> S;
	int s[S];
	for(int j = 0; j < S; j++) {
		std::cin >> s[j];
	}
	std::cin >> M;
	int m[M];
	for(int k = 0; k < M; k++) {
		std::cin >> m[k];
	}
	
	std::sort(x, x + N);
	std::sort(s, s + S);
	
	int jobsCreated = 0;
	for(int monkI = 0, jobI = 0; monkI < N; monkI++) {
		while(jobI < S && s[jobI] < x[monkI]) jobI++;
		if(jobI < S) {
			jobsCreated++;
			jobI++;
		} else {
			break;
		}
	}
	
	std::sort(x, x + N, std::greater<int>());
	std::sort(m, m + M, std::greater<int>());
	for(int monkI = 0, jobI = 0; monkI < N; monkI++) {
		while(jobI < M && m[jobI] > x[monkI]) jobI++;
		if(jobI < M) {
			jobsCreated++;
			jobI++;
		} else {
			break;
		}
	}
	
	std::cout << std::min(jobsCreated, N);
	
	return 0;
}