#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<time.h>
#include<graphics.h>
#include<windows.h>
#define isize 400
#define increase 100
#define ERROR 0
#define OVERFLOW -2
#define max 20
typedef struct {
	int x;
	int y;
}ptype;

typedef struct {
	int flag;
	ptype pos;
	int n;
	int f;
}dot;

typedef dot* type;

typedef struct {
	type* top;
	type* base;
	int size;
}stack;

int initmaze(char a[][max]) {
	int i, j;
	for (j = 0; j<max; j++)
		a[0][j] = j;
	for (i = 0; i <max; i++)
		a[i][0] = i;
	for (j = 1; j<max; j++)
		a[max - 1][j] = 0;
	for (i = max - 2; i > 0; i--)
		a[i][max-1] = 0;
	srand(time(NULL));
	for (i = 1; i<max - 1; i++) {
		for (j = 1; j<max-1; j++) {
			a[i][j] = rand() % 3;
		}
	}
	for (i = 1; i<max - 1; i++) {
		for (j = 1; j<max-1; j++) {
			if (a[i][j] == 0 || a[i][j] == 2)
				a[i][j] = ' ';
			if (a[i][j] == 1)
				a[i][j] = 64;
		}
	}
	a[1][1] = 'S';
	a[max-2][max - 2] = 'E';

	return 1;
}

int move(dot *&cur,dot *&be) {
	dot* t;
	switch (cur->n) {
	case 1:
		t=cur+1;
		if (t->flag&&cur->f != 3) {
			(cur->n)+=1;
			be = cur;
			cur = t;
			cur->f = 1;
			break;
		}
		else
			cur->n+=1;
		
	case 2: 
		t = cur + max;
		if (t->flag&&cur->f!=4) {
			cur->n+=1;
			be = cur;
			cur = t;
			cur->f = 2;
			break;
		}
		else
			cur->n+=1;
	
	case 3: 
		t = cur - 1;
		if (t->flag&&cur->f!=1) {
			cur->n+=1;
			be = cur;
			cur = t;
			cur->f = 3;
			break;
		}
		else
			cur->n+=1;
	
	case 4: 
		t = cur - max;
		if (t->flag&&cur->f!=2) {
			cur->n+=1;
			be = cur;
			cur = t;
			cur->f = 4;
			break;
		}
		else
			cur->n+=1;
	
	default:
		cur->flag = 0;

		return 0;
	
		
	}
	return 1;
}

int init(stack &L) {
	L.base = L.top = (type*)malloc(sizeof(stack)*isize);
	if (!L.top) return OVERFLOW;
	L.size = isize;
	return 1;
}

int push(stack &L, type e) {
	if (L.top - L.base >= L.size) {
		L.base = (type*)realloc(L.base, sizeof(stack)*(L.size + increase));
		if (!L.base) return OVERFLOW;
		L.top = L.base + L.size;
		L.size = L.size + increase;
	}
	*L.top = e;
	L.top++;
	return 1;
}

int  pop(stack &L, type &e) {
	if (L.top == L.base) return ERROR;
	e = *(L.top-1);
	L.top--;
	return 1;
}

int gettop(stack &L, type &e) {
	if (L.top == L.base) return ERROR;
	e = *(L.top - 1);
	return 1;
}

int show(stack &L) {
	
	if (L.top == L.base) { printf("ø’’ª"); return ERROR; }
	type* p = L.base;
	while (p != L.top) {
		printf("%d  ", *p);
		p++;
	}
	printf("n");
	return 1;
}

int solve(char a[][max], dot d[][max], ptype p[][max], stack &s) {
	int i, j;
	for (i = 0; i < max; i++) {
		for (j = 0; j < max; j++) {
			p[i][j].x = i;
			p[i][j].y = j;
			if (a[i][j] == ' ' || a[i][j] == 'S' || a[i][j] == 'E') {
				d[i][j].flag = 1;
				d[i][j].pos.x = i;
				d[i][j].pos.y = j;
				d[i][j].n = 1;
				d[i][j].f = 0;
			}
			else {
				d[i][j].flag = 0;
				d[i][j].pos.x = i;
				d[i][j].pos.y = j;
				d[i][j].n = 0;
				d[i][j].f = 0;
			}	
		}
	}
dot *cur=&d[1][1];

	dot* e;
	dot* b = cur;
	int r;
	dot* E = &d[max-2][max-2];	
	printf("THE WAY IS:");
	do{
		printf("(%d,%d) ", cur->pos.x, cur->pos.y); Sleep(10);
			
			r = move(cur,b);
			if (r) {
				if (gettop(s,e)) {
					if (b->pos.x != e->pos.x || b->pos.y != e->pos.y)
						push(s, b);
					else {
						pop(s, e);
						push(s, b);
					}
				}
				else
					push(s, b);
				continue;
			}

			if (!r) {
				pop(s, e);
				push(s, b);
                gettop(s, e);
				cur = e;
			
				if (cur->n > 4) {
					pop(s, e); 
					if (s.top == s.base)
						return 0; 
					gettop(s, e);
					cur = e;
				}	
		}
	} while (s.top != s.base && cur != E);
	return 1;
}

int main() {
	char maze[max][max];
	initmaze(maze);

	int i, j;
	for (i = 0; i<max; i++) {
		for (j = 0; j<max; j++) {
			if (i == max - 1 || j == 0 || i == 0 || j == max - 1)
				printf("%2d", maze[i][j]);
			else
				printf("%2c", maze[i][j]);
		}
		printf("\n");
	}

	dot Dot[max][max];
	ptype Ptype[max][max];
	stack S;
	init(S);
	solve(maze, Dot, Ptype, S); 
	getchar();
	return 0;
}
