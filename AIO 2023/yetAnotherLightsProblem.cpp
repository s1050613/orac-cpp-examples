#include <iostream>
#include <queue>
#include <set>

// #define TESTING

std::set<std::pair<int, int>> moves;

void printBoard(bool** board, int R, int C) {
	#ifdef TESTING
		for(int y = 0; y < R; y++) {
			for(int x = 0; x < C; x++) {
				std::cout << (board[y][x]? '*' : '.') << " ";
			}
			std::cout << std::endl;
		}
		std::cout << "---------------------------------" << std::endl;
	#endif
}
void addMove(std::pair<int, int> pos) {
	if(moves.count(pos)) {
		moves.erase(pos);
	} else {
		moves.insert(pos);
	}
}
void crossFlip(bool** board, int r, int c, int R, int C) {
	for(int x = 0; x < C; x++) {
		board[r][x] = !board[r][x];
	}
	for(int y = 0; y < R; y++) {
		board[y][c] = !board[y][c];
	}
	board[r][c] = !board[r][c];
	#ifdef TESTING
		std::cout << "Flipped grid at (r, c) = (" << r << ", " << c << ")" << std::endl;
		printBoard(board, R, C);
	#endif
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	auto f = freopen("yalpin.txt", "r", stdin);
	#ifndef TESTING
		freopen("yalpout.txt", "w", stdout);
	#endif
	
	int R, C;
	std::cin >> R >> C;
	int evenR = R - R % 2, evenC = C - C % 2;
	std::queue<std::pair<int, int>> ogOffLampsInEvenEvenBlock;
	bool** board = new bool*[R];
	bool** originalBoard = new bool*[R];
	for(int y = 0; y < R; y++) {
		board[y] = new bool[C];
		originalBoard[y] = new bool[C];
		for(int x = 0; x < C; x++) {
			char ch;
			std::cin >> ch;
			board[y][x] = ch == '*';
			originalBoard[y][x] = ch == '*';
			if(y < evenR && x < evenC && ch == '.') {
				#ifdef TESTING
					std::cout << "OG off lamp in even-even block at (r, c) = (" << y << ", " << x << ")" << std::endl;
				#endif
				ogOffLampsInEvenEvenBlock.push({y, x});
			}
		}	
	}
	printBoard(board, R, C);
	
	// Flipping across a cross in an even-even grid will toggle the single cell. We first deal with the largest even-even block first, then deal with the edge rows later.
	while(!ogOffLampsInEvenEvenBlock.empty()) {
		std::pair<int, int> pos = ogOffLampsInEvenEvenBlock.front();
		ogOffLampsInEvenEvenBlock.pop();
		int r = pos.first, c = pos.second;
		for(int x = 0; x < evenC; x++) {
			addMove({r, x});
		}
		for(int y = 0; y < evenR; y++) {
			if(y == r) {
				continue;
			}
			addMove({y, c});
		}
		board[r][c] = !board[r][c];
		if(R % 2) { // This even-even crossflip will also affect the extra row/column - it flips all in there, except for the one in the same row/column
			for(int x = 0; x < evenC; x++) {
				if(x == c) {
					continue;
				}
				board[R - 1][x] = !board[R - 1][x];
			}
		}
		if(C % 2) {
			for(int y = 0; y < evenR; y++) {
				if(y == r) {
					continue;
				}
				board[y][C - 1] = !board[y][C - 1];
			}
		}
		#ifdef TESTING
			std::cout << "e-e cross-flip at (" << r << ", " << c << ")\n";
		#endif
		printBoard(board, R, C);
	}
	#ifdef TESTING
		std::cout << "board after solving even-even block:" << std::endl;
		printBoard(board, R, C);
	#endif
	if(R % 2 && C % 2) {
		int onLights = 0;
		for(int y = 0; y < R; y++) {
			onLights += board[y][C - 1];
		}
		for(int x = 0; x < C - 1; x++) {
			onLights += board[R - 1][x];
		}
		if(!onLights) {
			addMove({R - 1, C - 1}); // If all are off, crossflip the bottom-right corner
		} else if(onLights < R + C - 1) {
			std::cout << -1;
			return 0;
		}
	}
	if(R % 2) { // Odd number of rows - we have to deal with the strip at the bottom first. For this case we assume the number of columns is even.
		int onLights = 0;
		for(int x = 0; x < C; x++) {
			onLights += (int)board[R - 1][x];
		}
		if(!onLights) { // All lights are off
			#ifdef TESTING
				std::cout << "all lights are off on edge row\n";
			#endif
			for(int y = 0; y < R - 1; y++) {
				addMove({y, 0});
			}
			for(int x = 0; x < evenC; x++) {
				if(x) {
					addMove({R - 1, x});
				}
			}
		} else if(onLights < C) { // Not all lights are on
			std::cout << -1;
			return 0;
		}
	}
	#ifdef TESTING
		std::cout << "board after solving bottom row:" << std::endl;
		printBoard(board, R, C);
	#endif
	if(C % 2) { // Odd number of rows - we have to deal with the strip at the bottom first. For this case we assume the number of columns is even.
		int onLights = 0;
		for(int y = 0; y < R; y++) {
			onLights += (int)board[y][C - 1];
		}
		if(!onLights) { // All lights are off
			#ifdef TESTING
				std::cout << "all lights are off on edge column\n";
			#endif
			for(int x = 0; x < C - 1; x++) {
				addMove({0, x});
			}
			for(int y = 0; y < evenR; y++) {
				if(y) {
					addMove({y, C - 1});
				}
			}
		} else if(onLights < R) { // Not all lights are on
			std::cout << -1;
			return 0;
		}
	}
	
	#ifdef TESTING
		std::cout << "TOTAL MOVES: ";
	#endif
	std::cout << moves.size() << std::endl;
	#ifdef TESTING
			printBoard(originalBoard, R, C);
	#endif
	int i = 0;
	for(std::set<std::pair<int, int>>::iterator it = moves.begin(); it != moves.end(); it++) {
		std::pair<int, int> move = *it;
		#ifdef TESTING
			std::cout << "move " << i++ << std::endl;
			crossFlip(originalBoard, move.first, move.second, R, C);
		#else
			std::cout << move.first << " " << move.second << std::endl;
		#endif
	}
	
	return 0;
}