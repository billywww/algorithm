#include<stdio.h>
#include<malloc.h>

typedef struct Node {
	int flag;
	union {
		int data;
		struct { struct Node* hp; struct Node* tp; } ptr;
	};
}*Lnode;

int create(Lnode *L, char *a) {
	*L = (Lnode)malloc(sizeof(struct Node));
	(*L)->flag = 1;
	(*L)->ptr.hp = NULL;
	(*L)->ptr.tp = NULL;

	static char *p = a;
	int ch = 0;
	while (*++p != '\0') {
		if (*p == ',') {
			ch = 1;
		}
		if (!ch) {
			if (*p == '(') {
				create(&(*L)->ptr.hp, p);
				continue;
			}
			if (*p >= '0'&&*p <= '9') {
				(*L)->ptr.hp = (Lnode)malloc(sizeof(struct Node));
				(*L)->ptr.hp->data = *p-'0';
				(*L)->flag = 0;
			}
			if (*p == ')') break;
		}
		else {
				create(&(*L)->ptr.tp, p);
		}
	}
	return 1;
}

int deep(Lnode L) {
	if (L->flag == 0) return 0;
	if (!L) return 1;
	Lnode p = L;
	int max=0, temp;
	for (; p; p = p->ptr.tp) {
		temp = deep(p->ptr.hp);
		max = (temp > max ? temp : max);
	}
	return max + 1;
}

int traverse(Lnode L) {

}

