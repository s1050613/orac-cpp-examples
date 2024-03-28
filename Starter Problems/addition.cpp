#include <iostream>

int main() {
	freopen("addin.txt", "r", stdin);
	freopen("addout.txt", "w", stdout);
	int a, b;
	std::cin >> a >> b;
	std::cout << a + b;
	
	return 0;
}