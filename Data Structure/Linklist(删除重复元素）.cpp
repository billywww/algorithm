#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef int type;

typedef struct LNode{
	type data;
	struct LNode *next;
}LNode,*Linklist;
 
void differ(Linklist &La){
	Linklist p,q;
	p=La;
	while(p->next){
		q=p->next->next;
		while(q&&p->next->data!=q->data){
			q=q->next;
		}
		if(q){
			p->next=p->next->next;
			p=p->next; 	
		}
		else{
			p=p->next;
		}
	}
}

void create (Linklist &L,int n){
	L=(Linklist)malloc(sizeof(Linklist));
	L->next=NULL;
	int i;
	Linklist p,q;
	q=L;
	for(i=0;i<n;i++){
		p=(Linklist)malloc(sizeof(LNode));
		p->next=q->next;
		q->next=p;
		scanf("%d",&(p->data));
		q=p;	
	}
}

void show(Linklist L){
	Linklist p;
	p=L->next;
	while(p){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

int main(){
	Linklist List;
	int n=6;
	printf("enter 6 numbers\n") ;
	create(List,n);
	show(List);
	differ(List);
	show(List);
	return 0;
}
