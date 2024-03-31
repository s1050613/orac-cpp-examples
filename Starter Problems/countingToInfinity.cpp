#include <iostream>
 
int main() {
	freopen("countin.txt", "r", stdin);
	freopen("countout.txt", "w", stdout);
	
	int n;
	std::cin >> n;
	for(int i = 1; i <= n; i++) {
		std::cout << i << std::endl;
	}
	
	return 0;
}