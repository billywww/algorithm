//Linklist

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct LNode{
	type data;
	struct LNode next;
}LNode,*Link;

typedef struct{
	Link head,tail;
	int Len
}Linklist;

int Initlist(Linklist &L){
	L=(Link)malloc(sizeof(LNode));
	if(!L) return OVERFLOW;
	Linklist.head=L;
	Linklist.head->next=NULL;
	Linklist.Len=0;
	return 1;
} 

int Createlist(Link &L,type a[],int n){
	int k;
	Link p;
	p=L->next;
	for(k=0,k<n,k++){
		p=(Link)malloc(sizeof(LNode));
		if(!p) return OVERFLOW;
		p->data=a[k];
		p=p->next;
		Linklist.
	}
	
}
