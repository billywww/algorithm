#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


typedef struct Lnode {
	int info[5];//{ret, n, x, y, z}
	struct Lnode * next;
}S;
typedef S* stack;

int initstack(stack &L) {
	L = (stack)malloc(sizeof(S));
	//if()
	L->next = NULL;
	return 1;
}

int push(stack &L,int e[]) {
	stack p = (stack)malloc(sizeof(S));
	int i = 0;
	while (i < 5) {
		p->info[i] = e[i];
		i++;
	}
	p->next = L->next;
	L->next = p;
	return 1;
}

int pop(stack &L, int e[]) {
	if (L->next) {
		stack p = L->next;
		int i = 0;
		while (i < 5) {
			e[i]=p->info[i];
			i++;
		}
		
		L->next = L->next->next;
		free(p);
		p = NULL;
		return 1;
	}
	else return 0;
}

int gettop(stack L, int e[]) {
	if (L->next) {
		int i = 0;
		//printf(" %x ", L -> next);
		while (i < 5) {
			e[i] = L->next->info[i];
			i++;
		}
	}
	else 
		return 0;	
	return 1;
}
int move(int a, int b, int c) {
	printf("move No.%d from column %d to column %d.\n", a, b, c);
	return 1;
}

int hanoi(int num,int a, int b, int c) {
	S k;
	stack s=&k;
	initstack(s);
	//printf("%x ", s->next);
	int temp;
	int e[5] = {0,num,a,b,c };
	push(s, e); //printf("%x ", s->next->next);
	while (gettop(s, e)) {
		pop(s, e);
		switch (e[0]) {
		case 0:
			if (e[1] == 1)
				move(e[1], e[2], e[4]);
			else {
				e[0] = 3;
				push(s, e);
				e[0] = 0;
				e[1] = e[1] - 1;
				temp = e[3];
				e[3] = e[4];
				e[4] = temp;
				push(s, e);
			}
			continue;
			break;
		case 3:
			move(e[1], e[2], e[4]);
			e[0] = 5;
			push(s, e);
			continue;
			break;
		case 5:
			e[0] = 7;
			push(s, e);
			e[0] = 0;
			e[1] = e[1] - 1;
			temp = e[3];
			e[3] = e[2];
			e[2] = temp;
			push(s, e);
			continue;
			break;
		case 7:
			continue;
		}		
	}
	return 1;
}
int main() {
	int n;
	printf("Input how many blocks do you want to move?");
	scanf("%d", &n);
	int a = 1;
	int b = 2;
	int c = 3;
	hanoi(n, a, b, c);
	getchar();
	getchar();
	return 0;
}
