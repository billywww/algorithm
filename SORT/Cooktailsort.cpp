#include<stdio.h>
int sort(int *a, int n) {
	int j,i;
	int left, right;
	int temp;
	for (left = 0, right = n - 1; left < right; left++, right--) {
		for (i = left; i < right; i++) {
			if (a[i] > a[i + 1]) {
				temp = a[i];
				a[i]=a[i+1];
				a[i+1] = temp;
			}
		}
		for (i = right - 1; i > left; i--) {
			if (a[i] < a[i - 1]) {
				temp = a[i];
				a[i] = a[i - 1];
				a[i - 1] = temp;
			}
		}
	}
	return 1;
}
int main() {
	int a[100];
	int k = 0;
	while (scanf_s("%d", &a[k++]) && getchar() != '\n');
	sort(a, k);
	int i = 0;
	while (i < k) {
		printf("%d ", a[i++]);
	}
	getchar();
	return 0;
}