//EVALUATION
//OUTPUT THE RESULT ONLY BETWEEN -128 AND 127

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef int type2;
typedef char type1;
#define ERROR 0
#define max 20

// STACK DEFINATION WITHOUT HEAD NODE
typedef struct Lnode {
	type1 data;
	struct Lnode* next;
}stack, *Linkstack;

int initstack(Linkstack &L) {
	L = NULL;
	return 1;
}

int push(Linkstack &L, type1 e) {
	Linkstack p;
	p = (Linkstack)malloc(sizeof(stack));
	//if(!p)
	p->data = e;
	p->next = L;
	L = p;
	return 1;
}

int pop(Linkstack &L, type1 &e) {
	if (L) {
		Linkstack p;
		p = L;
		e = L->data;
		L = L->next;
		free(p);
	}
	else return ERROR;
	return 1;
}

int gettop(Linkstack L, type1 &e) {
	if (L) {
		e = L->data;
	}
	else return ERROR;
	return 1;
}

//STACK DEFINNATION ABOVE

int s_fgets(char *a, int m) {                             //GET THE INPUT AND DELETE THE ENTER
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

int convert(char* a) {                                      //CHAR TO INT
	int i=-1;
	int temp=0;
	int k=1; 
	char e;
	int flag = 0;
	Linkstack s;
	initstack(s);
	while (a[++i] != '\0');
	i--;
	while (a[i] != '#') {
		k = 1;
		while (a[i]>=48&&a[i]<=57) {
			temp+= k*(a[i] - '0');
				k*=10;
				i--;
				flag = 1;
		}
		if (flag) {
			char t = a[i - 1];
			if (a[i] == '-' && (t < 48 || t>57)) {
				push(s, -temp);
				i--;
				temp = 0;
				flag = 0;
			}
			else {
				push(s, temp);
				temp = 0;
				flag = 0;
			}
		}
		else {
			push(s, a[i]);
			i--;
		}	
	}
	i = 1;
	while(gettop(s,e)){
		a[i++] = e;
		pop(s, e);
	}
	a[i] = '\0';
	return 1;
}

int compare(char a, char b) {                          //PRIORITY COMPARISON
	int c;
	if (a == '*' || a == '/')
		a = 1;
	if (a == '+' || a == '-')
		a = 0;
	if (b == '*' || b == '/')
		b = 1;
	if (b == '+' || b == '-')
		b = 0;
	c = (a >= b);
	return c;
}

int qianzhui(char* a) {                                    //CONVERT TO PRIFIX EXPRESSION
	Linkstack stacki;
	initstack(stacki);
	Linkstack stackc;
	initstack(stackc);

	char ec;
	char e;
	int f;
	int i = -1;
	while (a[++i] != '\0');
	i--;
	while (a[i] != '#') {
		if (a[i] != '+'&&a[i] != '-'&&a[i] != '*'&&a[i] != '/'&&a[i] != '('&&a[i] != ')')
		{
			push(stacki, a[i]);
		}
		else {
			if (a[i] != '(')
			{
				if (!gettop(stackc, ec)) {
					push(stackc, a[i]);
				}
				else {
					while (gettop(stackc, ec)) {
						if (ec == ')') {
							push(stackc, a[i]);
							break;
						}
						else {
							f = compare(a[i], ec);
							if (f) {
								push(stackc, a[i]);
								break;
							}
							else {
								pop(stackc, e);
								push(stacki, e);
								continue;
							}
						}
					}
					if (!gettop(stackc, ec))
						push(stackc, a[i]);
				}
			}
			else {
				while (gettop(stackc, ec) && ec != ')') {
					pop(stackc, e);
					push(stacki, e);
				}
				pop(stackc, e);
			}
		}
		i--;
	}
	while (gettop(stackc, e)) {
		pop(stackc, e);
		push(stacki, e);
	}
	int j;
	j = 1;
	while (gettop(stacki, e)) {
		pop(stacki, e);
		a[j] = e;
		j++;
	}
	a[j] = '\0';
	//printf("%s", a);
	return 1;
}
int evaluation(char* a, int& result) {                //EVALUATE THE EXPRESSION
	int i = -1;
	type1 e1, e2;
	type1 temp;
	Linkstack stack;
	initstack(stack);
	while (a[++i] != '\0');
	i -= 1;
	while (a[i] != '#') {
		if (a[i] != '+'&&a[i] != '-'&&a[i] != '*'&&a[i] != '/')
		{
			push(stack, a[i]);
		}
		else {
			pop(stack, e1);
			if (!pop(stack, e2)) {
				e2 = e1; e1 = 0;
			}
			switch (a[i]) {
			case '+':
				temp = e1 + e2;
				break;
			case '-':
				temp = e1- e2;
				break;
			case '*':
				temp = (e1) * (e2);
				break;
			case '/':
				temp = (e1) /( e2);
				break;
			default:
				break;
			}

			push(stack, temp);
		}
		i--;
	}
	gettop(stack, e1);
	result = e1;
	return 1;
}

int main() {
	char a[max];
	int result;
	printf("Please Enter The Expression:");
	s_fgets(a, max);
	convert(a);
	qianzhui(a);
	evaluation(a, result);
	printf("\nThe Result Is :%d", result);
	getchar();
	return 0;
}
