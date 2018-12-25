
#include<stdio.h>
#include<limits.h>

int cross(int* a, int m, int r, int n) {
	int i;
	int max=INT_MIN, sum=0;
	int total;
	for (i = r; i >= m; i--) {
		sum += a[i];
		if (sum > max) {
			max = sum;
		}
	}
	total = max;
	sum = 0; max = INT_MIN;
	for (i = r + 1; i <= n; i++) {
		sum += a[i];
		if (sum > max) {
			max = sum;
		}
	}
	total += max;
	return total;
}

int maxarray(int *a, int m, int n) {
	int left, right, mid;
	if (m == n) {
		return a[m];
	}
	else {
		int r = (m + n) / 2;
		left=maxarray(a, m, r);
		right=maxarray(a, r + 1, n);
		mid=cross(a, m, r, n);
	}
	return (left > right) ? (left > mid ? left : mid) : (right > mid ? right : mid);
}

int main() {
	int a[] = { -3,-2,-2,-5,-3,-4,-6,7,-8,-3,-5,-9 };

	printf("the maxsubset:%d\n",maxarray(a, 0, 11));
	getchar();
	return 0;
}
