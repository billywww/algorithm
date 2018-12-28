#include<stdio.h>

void a(char , int );

int main() {
	a(' ', 6);
	a('*', 3);
	printf("how are you");
	return 0;
}
void a(char c,int n) {
	int i = 1;
	while (i++ <= n)
		printf("%c", c);
}
