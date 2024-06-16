#include <iostream>
#include <map>

int main() {
	freopen("melodyin.txt", "r", stdin);
	freopen("melodyout.txt", "w", stdout);
	
	int n, k, c = 0, maxFreq, modeNote;
	std::cin >> n >> k;
	int s[n];
	std::map<int, int> notes[3];
	std::map<int, int> notePos;
	for(int i = 0; i < n; i++) {
		std::cin >> s[i];
		notes[i % 3][s[i]]++;
	}
	for(int i = 0; i < 3; i++) {
		notePos = notes[i];
		maxFreq = 0;
		for(auto& [note, freq] : notePos) {
			if(freq > maxFreq) {
				maxFreq = freq;
				modeNote = note;
			}
		}
		for(auto& [note, freq] : notePos) {
			if(note != modeNote) {
				c += freq;
			}
		}
	}
	std::cout << c;
	
	return 0;
}