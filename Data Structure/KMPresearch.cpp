//*****************KMP
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define Isize 100

typedef struct {
	char *elem;
	int length;
}Sstring;

int strassign(Sstring &S, char *p) {
	S.elem = (char*)malloc(sizeof(char)*Isize);
	//if(enough space)
	S.length = 0;
	char* q = S.elem;
	while (*p != '\0') {
		*q = *p;
		q++;
		p++;
		S.length++;
	}
	*q = '\0';
	return 1;
}

int next(Sstring L, int *n) {
	int p, k;
	n[0] = 0;
	k = 0;
	for (p = 1; p < L.length; p++) {
		while (k >0 && L.elem[p] != L.elem[k]) {
			k = n[k-1];
		}
		if (L.elem[p] == L.elem[k]) {
			
			k += 1;
		}
		n[p] = k;
	}
	n[p] = '\0';	
	return 1;
}

int research(Sstring S, Sstring L, int* p,int *n) {
	int j = 0;
	int i = 0;
	int k = 0;
	int m;
	int q = L.length;
	for (m = 0; m < S.length; m++) {
		while(k > 0 && S.elem[m] != L.elem[k]) {
			k = n[k - 1];
		}
		if (S.elem[m]==L.elem[k]) {
			k++;
		}
		if (k == q) {
			p[i++] = m - q + 2;
			k =n[k-1];
		}
	}
	p[i] = '\0';
	return 1;
}

int s_fgets(char *a, int m) {
	char* f;
	int i = 0;
	f = fgets(a, m, stdin);
	if (f) {
		while (a[i] != '\n'&&a[i] != '\0') {
			i++;
		}
		if (a[i] == '\n')
			a[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
		return 1;
	}
	return 0;
}
int main() {
	int n[Isize];
	Sstring S, L;
	int p[Isize];
	char a[Isize];
	char b[Isize];
	printf("ENTER STRING A:");
	s_fgets(a, Isize);
    printf("ENTER STRING B:");
	s_fgets(b, Isize);
	strassign(S, a);
	strassign(L, b);
	next(L, n);
	research(S, L, p,n);
	printf("B WAS FOUND IN A :");
	int i = 0;
	while (p[i]!='\0') {
		printf("%d ", p[i]);
		i++;
	}
	getchar();
	return 0;
}