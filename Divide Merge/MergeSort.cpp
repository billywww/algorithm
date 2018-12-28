#include<stdio.h>
#include<malloc.h>
int sortmerge(int*, int, int);
int merge(int *, int, int, int);

int sortmerge(int *A, int p, int r) {
	int q = ((r + p) / 2);
	if (r -1> p) {
		sortmerge(A, p, q);
		sortmerge(A, q + 1, r);
	}
	merge(A, p, q, r);
	return 1;
}

int merge(int *A, int p, int q, int r) {
	int *a = (int*)malloc(sizeof(int)*(r - p + 2));
	int i = p;
	int j = q + 1;
	while(i <= q&&j <= r) {
		if (A[i - 1] <= A[j - 1]) {
			*a++ = A[i - 1];
			i++;
		}
		else {
			*a++ = A[j - 1];
			j++;
		}
	}
	while (i <= q) {
		*a++ = A[i - 1];
		i++;
	}
	while (j <= r) {
		*a++ = A[j - 1];
		j++;
	}
	for (i = r - 1; i >=p - 1; i--) {
		A[i] = *--a;
	}
	return 1;
}

int main() {
	int a[100];
	int i = 0;
	while (scanf("%d", &a[i++])&&getchar()!='\n');
	a[i] = '\0';
	sortmerge(a, 1, 10);
	i = 0;
	while (a[i] != '\0') {
		printf("%d ", a[i++]);
	}
	getchar();
	return 0;
}
