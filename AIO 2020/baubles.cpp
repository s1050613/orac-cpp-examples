#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	freopen("baublesin.txt", "r", stdin);
	freopen("baublesout.txt", "w", stdout);
	
	int ro, bo, s, rp, bp;
	std::cin >> ro >> bo >> s >> rp >> bp;
	
	if(ro + s < rp || bo + s < bp || (ro + bo + s) < (rp + bp)) {
		std::cout << 0;
		return 0;
	}
	int solution;
	if(ro < rp && bo < bp) {
		int needed = rp - ro + bp - bo;
		solution = s - needed;
	} else {
		if(rp == 0) {
			solution = bo - bp + s;
		} else if(bp == 0) {
			solution = ro - rp + s;
		} else if(ro > rp && bo > bp) {
			solution = std::min(ro - rp, bo - bp) + s;
		} else {
			solution = s - std::max(rp - ro, bp - bo);
		}
	}
	std::cout << std::max(solution + 1, 0);
	
	return 0;
}