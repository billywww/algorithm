#include<stdio.h>
int sort(int* a, int n) {
	int i, j;
	int min;
	int temp;
	for (i = 0; i < n; i++) {
		min = i;
		for (j = i + 1; j < n; j++) {
			if (a[j] < a[min]) {
				min = j;
			}
		}
		if (min != i) {
			temp = a[i];
			a[i] = a[min];
			a[min] = temp;
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