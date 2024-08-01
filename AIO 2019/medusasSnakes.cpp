#include <iostream>
#include <map>

std::string dna;
bool checkVenom(int venom, int n) {
	int remainingLetters = venom * 5;
	char currentLetter = 'S';
	int repetitions = 0;
	for(int i = 0; i < n; i++) {
		while(i < n && dna[i] != currentLetter) i++;
		if(dna[i] == currentLetter) {
			repetitions++;
			remainingLetters--;
			if(repetitions == venom) {
				if(currentLetter == 'E') {
					return true;
				}
				switch(currentLetter) {
					case 'S':
						currentLetter = 'N';
						break;
					case 'N':
						currentLetter = 'A';
						break;
					case 'A':
						currentLetter = 'K';
						break;
					case 'K':
						currentLetter = 'E';
						break;
				}
				repetitions = 0;
			}
		}
		if(n - i - 1 < remainingLetters) break;
	}
	return false;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	freopen("snakein.txt", "r", stdin);
	freopen("snakeout.txt", "w", stdout);
	
	int n;
	std::cin >> n >> dna;
	std::map<char, int> charFreqs;
	for(int i = 0; i < n; i++) {
		char ch = dna[i];
		charFreqs[ch]++;
	}
	int highestVenom = std::min(charFreqs['S'], std::min(charFreqs['N'], std::min(charFreqs['A'], std::min(charFreqs['K'], charFreqs['E']))));
	
	int l = 1, h = highestVenom;
	int highestSol = 0;
	while(h - l > 0) {
		int venom = (l + h) / 2;
		if(checkVenom(venom, n)) {
			highestSol = venom;
			l = venom + 1;
		} else {
			h = venom;
		}
	}
	if(l == h && checkVenom(h, n)) {
		std::cout << h;
	} else {
		std::cout << highestSol;
	}
	
	return 0;
}