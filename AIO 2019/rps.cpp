#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	freopen("rpsin.txt", "r", stdin);
	freopen("rpsout.txt", "w", stdout);
	
	int n, ra, pa, sa, rb, pb, sb;
	std::cin >> n >> ra >> pa >> sa >> rb >> pb >> sb;
	int score = 0;
	for(int i = 0; i < n; i++) {
		if(i < ra) {
			// opponent does rock
			if(pb > 0) {
				pb--;
				score++;
			} else if(rb > 0) {
				rb--;
			} else {
				sb--;
				score--;
			}
		} else if(i < ra + pa) {
			// opponent does paper
			if(sb > 0) {
				sb--;
				score++;
			} else if(pb > 0) {
				pb--;
			} else {
				rb--;
				score--;
			}
		} else {
			// opponent does scissors
			if(rb > 0) {
				rb--;
				score++;
			} else if(sb > 0) {
				sb--;
			} else {
				pb--;
				score--;
			}
		}
	}
	std::cout << score;
	
	return 0;
}