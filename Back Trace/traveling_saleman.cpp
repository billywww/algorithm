#include<iostream>
#define DOT_NUM 4

int check(int*, int, int);
int  work(int(*)[4]);

int work(int(*t)[4]) {
	int min = 0x7fffffff;
	int sum = 0;
	int temp[5] = { 0,0,0,0,0 };
	int loc[5] = { 0,0,0,0,0 };

	int k = 1;
	int i;

	while (k > 0) {
		for (i = loc[k]; i < 4; i++) {
			if (t[temp[k - 1]][i] > 0 && check(temp, i, k)) {
				loc[k]++;
				temp[k] = i;
				k++;
				if (k > 4) {
					sum = t[temp[0]][temp[1]] + t[temp[1]][temp[2]] + t[temp[2]][temp[3]] + t[temp[3]][temp[4]];
					if (sum < min) {
						min = sum;
					}
					for (int i = 0; i <= 4; i++) {
						std::cout << temp[i];
					}
					std::cout << std::endl;
					k--;
				}
				break;
			}
			else
				loc[k]++;

		}
		if (loc[k] >= 4) {
			loc[k] = 0;
			temp[k] = 0;
			k--;
		}

	}
	return min;
}

int check(int * m, int n, int k) {
	if (k == 4 && n == 0) {
		return 1;
	}

	for (int i = 0; i < k; i++) {
		if (m[i] == n)
			return 0;
	}

	return 1;
}

int main() {
	int map[][4] = {
	  {0,30,6,4},
	  {30,0,5,10},
	  {6,5,0,20},
	  {4,10,20,0}
	};
	std::cout << work(map);

	return 0;
}
