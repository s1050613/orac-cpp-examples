#include <iostream>

int main() {
	freopen("chimin.txt", "r", stdin);
	freopen("chimout.txt", "w", stdout);
	
	int n, currentStringI, spliceAmount, splices = 0;
	std::string s, t, h;
	std::cin >> n >> s >> t >> h;
	
	char c;
	bool inFirst, inSecond;
	int current = -1;
	for(int i = 0; i < n; i++) {
		c = h[i];
		inFirst = s[i] == c;
		inSecond = t[i] == c;
		if(!inFirst && !inSecond) {
			std::cout << "PLAN FOILED";
			return 0;
		} else {
			if(current == -1) {
				if(inFirst && !inSecond) {
					current = 0;
				} else if(inSecond && !inFirst) {
					current = 1;
				}
			} else {
				if(current == 0 && !inFirst) {
					current = 1;
					splices++;
				} else if(current == 1 && !inSecond) {
					current = 0;
					splices++;
				}
			}
		}
	}
	std::cout << "SUCCESS" << std::endl << splices;
	
	return 0;
}