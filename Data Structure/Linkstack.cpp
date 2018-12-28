#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef int type2;
typedef char type1;
#define ERROR 0
#define max 20

// STACK DEFINATION
typedef struct Lnode {
	type1 data;
	struct Lnode* next;
 }stack,*Linkstack;

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
	if(L){
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
int main(){
	char e;
	Linkstack L;
	initstack(L);
	push(L,65);
	push(L,64); 
	gettop(L,e);
	printf("%c", e);
	pop(L, e);
	gettop(L, e);
	printf("%c", e);
	
	
	return 0;
} 
