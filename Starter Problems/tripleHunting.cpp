#include <iostream>
#include <list>
 
int main() {
	freopen("tripin.txt", "r", stdin);
	freopen("tripout.txt", "w", stdout);
	
	int n, k = 0;
	std::cin >> n;
	std::list<int> m;
	int l[n];
	for(int i = 0; i < n; i++) {
		std::cin >> l[i];
		if(l[i] % 3 == 0) {
			k++;
			m.push_back(i + 1);
		}
	}
	if(k == 0) {
		std::cout << "Nothing here!";
	} else {
		std::cout << k << std::endl;
		for(int x : m) {
			std::cout << x << " ";
		}
	}
	
	return 0;
}