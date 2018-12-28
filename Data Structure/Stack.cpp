#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef int type;
#define isize 10
#define increase 10
#define ERROR 0
#define OVERFLOW -2

typedef struct{
	type* top;
	type* base;
	int size;
}stack;

int init (stack &L){
	L.base=L.top=(type*)malloc(sizeof(stack)*isize);
	if(!L.top) return OVERFLOW;
	L.size=isize;
	return 1;
}

int push(stack &L,type e){
	if(L.top-L.base>=L.size){
		L.base=(type*)realloc(L.base,sizeof(stack)*(L.size+increase));
	if(!L.base) return OVERFLOW;
	L.top=L.base+L.size;
	L.size=L.size+increase;
    }
	*L.top=e;
	L.top++;
	return 1;
}

int  pop(stack &L,type &e){
	if(L.top==L.base) return ERROR;
	e=*L.top;
	L.top--;
	return 1;
}

int destory(stack &L){
	free(L.base);
	L.base=NULL;
	return 1;
}

int clear(stack &L){
	L.top=L.base;
	return 1;
}

int gettop(stack &L,type &e){
	if(L.top==L.base) return ERROR;
	e=*(L.top-1);
	return 1;
}

int show(stack &L){
	if(L.top==L.base) return ERROR;
	type* p=L.base;
	while(p!=L.top){
		printf("%d  ",*p);
		p++;
	}
	printf("\n");
	return 1;
}

int main(){
	stack S;
	init(S);
	int i;
	type e;
	for(i=0;i<isize;i++){
		scanf("%d",&e);
		push(S,e);
	}
	show(S);
	type a;
	pop(S,a);
	show(S);
	gettop(S,e);
	printf("%d",e);
	return 0;
}

