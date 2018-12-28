#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define isize 10
#define OVERFLOW -2
#define ERROR 0
#define max 20

typedef char type;
typedef struct{
	char *top;
	char *base;
	int size;
}stack;

int initstack(stack *L){
	L->base=L->top=(char*)malloc(sizeof(type)*isize);
	if(!L->base) return OVERFLOW;
	L->size=isize;
	return 1;
}

int createstack(stack* L,int n){
	char * p;
	p=L->top;
	int i=1;
	if(n>L->size){
		L->top=L->base=(char*)realloc(L->base,sizeof(type)*(isize+L->size));
	    //...
	}
	while(i<=n){
		scanf("%c",p);
		p++;
	}
	return 1;
}

int pop(stack *L,char &e){
	if(L->top==L->base)
	return ERROR;
	e=*L->top;
	L->top--;
	return 1;
}

int push(stack *L,char e){
	if(L->top-L->base==L->size){
		L->base=(char*)realloc(L->base,sizeof(stack)*(L->size+isize));
		//...
		L->top=L->base+L->size;
	    L->size=L->size+isize;
	}
	*L->top=e;
	L->top++;
} 

int main(){
	char a[max];
	stack* S;
	char e;
	int q;
	int flag=1;
	initstack(S);
	int i;
	for(i=0;i<max;i++){
		scanf("%c",&a[i]);
	}
	for(i=0;a[i]!='\0';i++){
	    if(a[i]=='('||'['){
		push(S,a[i]);
	}
	    if(a[i]==')'||']'){
		q=pop(S,e);
		if(e!=a[i]&&q)
		flag=0;
    } 
    if(S->base==S->top&&flag){
    	printf("true\n");
    }
    else
    printf("error\n");
    return 0;
}
}
