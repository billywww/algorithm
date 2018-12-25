#include<stdio.h>
#include<string.h>
#pragma  warning(disable:4996)

int sort(char(*a)[10], int n) {
	int flag = 1;
	int i, k = 9;
	int j = n;
	int c[200] = { 0 };
	char r[10][10];
	while (k>=0) {
		flag = 0;
		for (i = 0; i < n; i++) {
			if (a[i][k] != '\0') {
				flag = 1;
			}
			c[a[i][k]]++;
		}
		if (flag) {
			
			for (i = 98; i < 123; i++) {
				c[i] = c[i] + c[i - 1];
			}
			int x = c[122];
			for (i = n - 1; i >= 0; i--) {
				if (a[i][k] != '\0') {
					strcpy(r[c[a[i][k]]-1], a[i]);
					c[a[i][k]]--;
					
				}
				else {
					strcpy(r[x++], a[i]);
				}
			}
			for (i = 0; i < n; i++) {
				strcpy(a[i], r[i]);
			}
		}
			for (i = 97; i < 123; i++) {
				c[i] = 0;
			}
		k--;
	}
	return 1;
}

int main() {
	char a[10][10] = {
		{"apple"},{"apply"},{"app"},{"balana"},{"orange"},{"corp"},{"dis"},{"book"},{"zoo"},{"rock"}
	};
	sort(a, 10);
	int i = 0;
	while (i < 10) {
		puts(a[i]);
		i++;
	}
	getchar();
	return 0;
}