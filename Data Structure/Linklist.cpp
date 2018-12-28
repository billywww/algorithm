#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
typedef char type;
#define error 0
#define OVERFLOW -2


typedef struct LNode{
	type data;
	struct LNode *next;
} LNode,*Linklist;

int Initlist(Linklist &L){
	L=(Linklist)malloc(sizeof(LNode));
	if(!L) exit(OVERFLOW);
	else{
	  L->next=NULL;
	  return 1;
	  }
}//头节点

int Createlist(Linklist &L,int n){
	int i;
	Linklist p;
	Linklist q;
	for(i=0;i<n;i++){
		p=(Linklist)malloc(sizeof(LNode));
		scanf("%c",&(p->data));
		p->next=L->next; L->next=p;
	}fflush(stdin);
	return 1;
}//赋值

 int Listinsert(Linklist &L,int i,type e){
 	int k;
 	Linklist p;
 	p=L;
 	for(k=1;k<i;k++){
 		p=p->next;	
 		if(!p) return error;
 	}
 	Linklist q;
 	Initlist(q);
 	q->data=e;
 	q->next=p->next; p->next=q;
 	return 1;
 }//插入 
 
 int Listdelete(Linklist &L,int i,type &e) {
 	int k;
 	Linklist p;
 	p=L;
 	for(k=1;k<i;k++){
 		p=p->next;
 		if(!p) return error; 		
 	}
 	Linklist q;
 	q=p->next;
 	p->next=q->next;
 	e=q->data;
 	free(q);
 	q=NULL;
 	return 1;
 }//删除
 
 int Showlist(Linklist L){
 	Linklist p;
 	p=L->next;
 	while(p){	
 		printf("%c",p->data);
		 p=p->next;
 	}
 	p=NULL;
 	printf("\n");
	 return 1;	
 } //输出
 
 int Mergelist(Linklist &La,Linklist &Lb,Linklist &Lc) {
 	Linklist pa,pb,pc;
 	pa=La->next;
 	pb=Lb->next;
 	Lc=pc=La;
 	while(pa&&pb){
	  if(pa->data<=pb->data){
	    pc->next=pa;
	    pc=pa;
		pa=pa->next;
	    
 	}
 	if(pa->data>pb->data){
 		pc->next=pb;
		pc=pb;
	    pb=pb->next;    
 	}
 }
    while(pa) {
    pc->next=pa;break;}
    while(pb) {
    pc->next=pb;break;}
    free(Lb);
    Lb=NULL;
    return 1;
 }//合并
 
 int main (){
 	Linklist List_1;
 	Initlist(List_1);
 	printf("enter list_1 in reversed order  :\n");
 	Createlist(List_1,8);
 	printf("the list is:");
 	Showlist(List_1);
 	int i;
 	char a;
 	printf("please enter the location and the element to be inserted : " );
 	scanf("%d",&i);fflush(stdin);
 	scanf("%c",&a);fflush(stdin);
 	Listinsert(List_1,i,a);
 	printf("the list is : ");
 	Showlist(List_1);
 	int j;
 	char e;
 	printf("please enter the element to be deleted  : ");
 	scanf("%d",&j);fflush(stdin);
 	Listdelete(List_1,j,e);
 	printf("the list becomes : ");
 	Showlist(List_1);
 	
 	Linklist List_2;
 	Linklist List_3;
 	Initlist(List_2);
	printf("enter list_2 in reversed order  :\n");
 	Createlist(List_2,8);
 	printf("the list is:");
 	Showlist(List_2);
 	printf("merge these two lists : ");
 	Mergelist(List_1,List_2,List_3);
 	Showlist(List_3);
 	
 	return 0;
 	
 } 
