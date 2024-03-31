#include <iostream>
 
int main() {
	freopen("bendin.txt", "r", stdin);
	freopen("bendout.txt", "w", stdout);
	int x1, y1, x2, y2, X1, Y1, X2, Y2;
	std::cin >> x1 >> y1 >> x2 >> y2 >> X1 >> Y1 >> X2 >> Y2;
	int a = (x2 - x1) * (y2 - y1) + (X2 - X1) * (Y2 - Y1);
	int xOverlap = std::max(std::min(x2, X2) - std::max(x1, X1), 0);
	int yOverlap = std::max(std::min(y2, Y2) - std::max(y1, Y1), 0);
	
	std::cout << a - xOverlap * yOverlap;
	
	return 0;
}