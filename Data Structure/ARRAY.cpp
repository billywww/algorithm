#include<stdio.h>
#include<malloc.h>
#define adressof(v) (&reinterpret_cast<const char &>(v))
#define intsizeof(n) ((sizeof(n)+sizeof(int)-1)&~(sizeof(int)-1))
#define va_start(ap,v)  (ap=(char*)adressof(v)+intsizeof(v))
#define va_arg(ap,t) (*(t*)((ap+=intsizeof(t))-intsizeof(t)))
#define va_end(ap) ap=NULL

#define Max_dim 8
#define max 1000
typedef int type;

//*****************************************************∂‡Œ¨æÿ’Û


typedef struct {
	type* elem;
	int  dim;
	int * bounds;
	int * constant;
}Array;

int initarray(Array &A, int num, ...) {
	A.dim = num;
	A.bounds = (int*)malloc(sizeof(int)*num);
	//.....
	char* p;
	int i;
	int total=1;
	va_start(p,num);
	for (i = 0; i < num; i++) {
		A.bounds[i] = va_arg(p, int);
		//....
		total *= A.bounds[i];
	}
	A.elem = (type*)malloc(sizeof(type)*total);
	//....
	A.constant = (int*)malloc(sizeof(int)*num);
	//....
	A.constant[num-1]= 1;
	for (i = num-2; i >=0 ; i--) {
		A.constant[i] = A.bounds[i + 1] * A.constant[i + 1];
	}
	int *q = A.elem;
	for (i = 0; i < total; i++) {
		*q = 0;
		q++;
	}
	return 1;
}

int locate(Array A, char* &p, int &loc) {
	int k;
	int i;
	loc = 0;
	for (i = 1; i <= A.dim; i++) {
		k = va_arg(p, int);
		if (k <= A.bounds[i - 1] && k >= 1) {
			loc += (k - 1)*A.constant[i - 1];
		}
		else return 0;
	}
	return 1;
}

int value(Array &A, type e, ...) {
	char* p;
	va_start(p, e);
	int loc;
	if (locate(A, p, loc)) {
		*(A.elem + loc) = e;
		return 1;
	}
	else printf("input error");
	return 0;
}



//****************************************************œ° Ëæÿ’Û



typedef struct {
	type data;
	int x, y;
}triple;
typedef struct {
	triple L[max];
	int line,col,n;
	int rpos[max];
}TSmatrix;

int Create(TSmatrix &a,Array b) {
	int i;
	int k = 0;
	a.n = 0;
	int total=1;
	for (i = 0; i < b.dim; i++) {
		total *= b.bounds[i];
	}
	a.line = b.bounds[1];
	a.col = b.bounds[2];
	for (i = 0; i < total; i++) {
		if (b.elem[i] != 0) {
			a.L[k].data= b.elem[i];
			a.L[k].y = i %b.bounds[2]+1;
			a.L[k].x = i / b.bounds[2] + 1;
			k++;
			a.n++;
		}
	}

	return 1;
}

int show(TSmatrix a) {
	int i;
	if (a.n) {
		for (i = 0; i < a.n; i++) {
			printf("(%d,%d,%d) ", a.L[i].x, a.L[i].y, a.L[i].data);
		}
		printf("\n");
		return 1;
	}
	return 0;
}

int cpot(TSmatrix a, int *f) {
	int i;
	for (i = 0; i < a.n; i++) {
		f[a.L[i].y]++;
	}
	for (i = 1; i < a.col; i++) {
		f[i] = f[i - 1] + f[i];
	}
	return 1;
}

int rpos(TSmatrix a, int* f) {
	int i;
	int t;
	f[0] = 0;
	for (i = 0; i < a.n; i++) {
		f[a.L[i].x]++;
	}
	for (i = a.line; i>=1; i--) {
		f[i] = f[i - 1];
	}
	for (i = 1; i <= a.line; i++) {
		f[i] += f[i - 1];
	}
	return 1;
}
/*
int trans(TSmatrix a,TSmatrix &b) {
	int i;
	int k ;
	int j = 0;
	for (i = 0; i < a.col; i++) {
		for (k = 0; k < a.n; k++) {
			if (a.L[k].y == i+1) {
				b.L[j].x = a.L[k].y;
				b.L[j].y = a.L[k].x;
				b.L[j].data = a.L[j].data;
				j++;
			}
		}
	}
	b.line = a.col;
	b.col = a.line;
	b.n = a.n;
	return 1;
}*/

int trans(TSmatrix a, TSmatrix &b) {
	int f[100] = { 0 };
	int i;
	int k;
	cpot(a, f);
	for (i = 0; i < a.n; i++) {
		k = a.L[i].y;
		b.L[f[k - 1]].x = a.L[i].y;
		b.L[f[k - 1]].y = a.L[i].x;
		b.L[f[k - 1]].data = a.L[i].data;
		f[k - 1]++;
	}
	b.line = a.col;
	b.col = a.line;
	b.n = a.n;
	return 1;
}

/*
int multiple(TSmatrix a, TSmatrix b, TSmatrix &c) {
	int i;
	int j;
	int k = 0;
	int tem[100][100] = { 0 };
	for (i = 0; i < a.n; i++) {
		for (j = 0; j < b.n; j++) {
			if (a.L[i].y == b.L[j].x) {
				tem[a.L[i].x][b.L[j].y]+= a.L[i].data*b.L[j].data;
			}
		}
	}
	for (i = 1; i <= a.line; i++) {
		for (j = 1; j <= b.col; j++) {
			if (tem[i][j] != 0) {
				c.L[k].data = tem[i][j];
				c.L[k].x = i;
				c.L[k].y = j;
				k++;
			}
		}
	}
	c.line = a.line;
	c.col = b.col;
	c.n = k ;
	return 1;
}
*/

int multiple(TSmatrix a, TSmatrix b, TSmatrix &c) {
	c.line = a.line;
	c.col = b.col;
	
	int fa[100] = { 0 };
	int fb[100] = { 0 };
	rpos(a, fa);
	rpos(b, fb);
	int row, co;
	int i, j, n;
	n = 0;
	int s, e;
	int f, t;
	int k;

	for (row = 1; row <= a.line; row++) {
	    s = fa[row];
		if (row < a.line) {
			e = fa[row + 1];
		}
		else e = a.n;
		int tem[100] = { 0 };
		for (i = s; i < e; i++) {
			k = a.L[i].y;
			f = fb[k];
			if (k < b.line) {
				t = fb[k + 1];
			}
			else t = b.n;
			for (j = f; j < t; j++) {
				co= b.L[j].y;
				tem[co] += a.L[i].data*b.L[j].data;
			}
		}
		for (i = 1; i <=b.col; i++) {
			if (tem[i]) {
				c.L[n].data = tem[i];
				c.L[n].x = row;
				c.L[n].y = i;
				n++;
			}
		}//co = 0;
	}
	c.n = n;
	return 1;
}



//**************************************************œ° Ëæÿ’Ûµƒ Æ◊÷¡¥±Ì µœ÷



typedef struct Node{
	int x, y;
	int data;
	struct Node* right;
	struct Node* down;
}*OLnode;
typedef struct {
	OLnode rhead, dhead;
	int row, col, n;
}Larray;

int create(Larray &a,Array b) {
	int i;
	a.dhead = (OLnode)malloc(sizeof(struct Node)*b.bounds[2]);//if()...
	a.rhead = (OLnode)malloc(sizeof(struct Node)*b.bounds[1]);//if()...
	for (i = 0; i < b.bounds[2]; i++) {
		a.dhead[i].down = NULL; a.dhead[i].right = NULL;
	}
	for (i = 0; i < b.bounds[1]; i++) {
		a.rhead[i].down = NULL; a.rhead[i].right = NULL;
	}
	a.row = b.bounds[1];
	a.col = b.bounds[2];
	int total = 1;
	int k=0;
	OLnode p;
	for (i = 0; i < b.dim; i++) {
		total *= b.bounds[i];
	}
	for (i = total-1; i >=0; i--) {
		if (b.elem[i] != 0) {
			k++;
			p = (OLnode)malloc(sizeof(struct Node));
			int x = i / b.bounds[2];
			int y = i%b.bounds[2];
			p->x = x+1;
			p->y = y+1;
			p->data = b.elem[i];
			p->right = a.rhead[x].right;
			a.rhead[x].right = p;
			p->down = a.dhead[y].down;
			a.dhead[y].down = p;
		}
	}
	a.n = k;
	return 1;
}

int insert(Larray &a) {
	int x, y, e;
	scanf_s("%d %d %d", &x, &y, &e);
	//if(rational input)...

	OLnode p = (OLnode)malloc(sizeof(struct Node));//IF()...
	p->data = e;
	p->x = x;
	p->y = y;
	if (a.dhead[y-1].down == NULL) {
		p->down = a.dhead[y - 1].down;
		a.dhead[y - 1].down = p;
	}
	else {
		OLnode q = &a.dhead[y - 1];
		while (q->down != NULL&&q->down->x < p->x)
			q = q->down;
		p->down = q->down;
		q->down = p;
	}
	if (a.rhead[x - 1].right == NULL) {
		p->right = a.rhead[x - 1].right;
		a.rhead[x - 1].right = p;
	}
	else {
		OLnode q = &a.rhead[x - 1];
		while (q->right != NULL&&q->right->y < p->y) {
			q = q->right;
		}
		p->right = q->right;
		q->right = p;
	}
	a.n++;
	return 1;
}

int showLarray(Larray a) {
	int i;
	printf("order of row: ");
	for (i = 0; i < a.row; i++) {
		OLnode p = a.rhead[i].right;
		while (p != NULL) {
			printf("(%d,%d,%d) ", p->x, p->y, p->data);
			p = p->right;
		}
	}
	printf("\n");
	printf("order of column: ");
	for (i = 0; i < a.col; i++) {
		OLnode p = a.dhead[i].down;
		while (p != NULL) {
			printf("(%d,%d,%d) ", p->x, p->y, p->data);
			p = p->down;
		}
	}
	printf("\n");
	return 1;
}

int main() {
	Array a;
	initarray(a, 3, 1, 3, 4);

	value(a, 12, 1, 1, 1);
	value(a, 9, 1, 1, 4);
	value(a, 14, 1, 3, 1);
	value(a, 5, 1, 2, 2);
	TSmatrix b,c;
	Create(b, a); printf("TSmatrix a:");
	show(b);
	trans(b, c); printf("\ntranspose a: ");
	show(c);

	Array d;
	initarray(d, 3, 1, 4, 2);
	value(d, 2, 1, 1, 2);
	value(d, 1, 1, 2, 1);
	value(d, -2, 1, 3, 1);
	value(d, 4, 1, 3, 2);
	TSmatrix e;
	Create(e, d); printf("\nTSmatrix b: ");
	show(e);

	TSmatrix m; printf("\nMultiple a and b : ");
	multiple(b, e, m);
	show(m);

	printf("\nArray a in form of Cross Linklist__\n");
	Larray Q;
	create(Q, a);
	showLarray(Q); printf("\nenter the triple to be inserted:");
	insert(Q);
	showLarray(Q);

	getchar(); getchar();
	return 0;
}