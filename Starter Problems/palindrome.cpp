#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	freopen("palin.txt", "r", stdin);
	freopen("palout.txt", "w", stdout);
	
	int n;
	std::string w;
	std::cin >> n >> w;
	std::string a = w, b = w;
	for(int i = 0; i < n / 2; i++) {
		if(w[i] != w[n - 1 - i]) {
			if(w[i] < w[n - 1 - i]) {
				w[n - 1 - i] = w[i];
			} else {
				w[i] = w[n - i - 1];
			}
		}
	}
	std::cout << w;
	
	return 0;
}