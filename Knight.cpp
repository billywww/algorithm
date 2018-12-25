#pragma  warning(disable:4996)
#include<iostream>
#include<iomanip>
#define max 5
int dx[8] = { 1,1,2,2,-1,-1,-2,-2 };
int dy[8] = { 2,-2,1,-1,2,-2,1,-1 };

int trace(int(*map)[max], int x, int y) {
	static int step = 0;
	static int count = 0;

	if (x < max&& x >= 0 && y < max && y >= 0 && !map[x][y]) {	
		step++;
		map[x][y] = step;
		if (step == max*max) {

			int i, j;
			for (i = 0; i < max; i++) {
				for (j = 0; j < max; j++) {
					std::cout << std::setw(3) << map[i][j];
				}
				std::cout << std::endl;
			}std::cout << std::endl;

		count++;
		map[x][y] = 0;
		step--;
		return 1;
	}
		int i;
		for (i = 0; i <= 7; i++) {
			trace(map, x + dx[i], y + dy[i]);
		}
		map[x][y] = 0;
		step--;
		return count;
	}

	else {
		return 1;
	}
}

int main() {
	int map[max][max] = { 0 };
	int sx, sy;
	std::cin >> sx >> sy;
	std::cout<<trace(map, sx, sy)<<std::endl;
	getchar(); getchar();
	return 0;
}