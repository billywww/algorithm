#include<stdio.h>

#include<malloc.h>

#define ERROR 0

typedef char ElemType;

typedef struct LNode

{

	ElemType data;

	struct LNode *next;

}LNode, *LinkList; 

int CreateList(LinkList &L,int n)

{

	L=(LinkList)malloc(sizeof(LNode));

	if(L==NULL)

	{

		printf("ÉêÇëÊ§°Ü£¡");

		return ERROR; 

	}

	L->next=NULL;

	printf("ÊäÈë×Ö·û´®:");

	int i;

	for(i=0;i<n;i++)

	{

		LinkList p=(LinkList)malloc(sizeof(LNode));

		if(p==NULL)

		{

			printf("ÉêÇëÊ§°Ü!");

		    return ERROR;

		}

		scanf("%c",&p->data);

        p->next=L->next; L->next=p;

	}	

}//Í·²å·¨ÊäÈën¸öÔªËØ

void Show(LinkList L)

{

	LinkList p=L->next;

	printf("×Ö·û´®Îª:");

	while(p)

	{

		printf("%c",p->data);

		p=p->next;

	}

	printf("\n"); 

}

int ListInsert(LinkList &L,int I,ElemType e)

{

	LinkList p=L;

	int k=0;

	while(p&&k<I-1)

	{

		p=p->next;

		++k;

	}

	if(!p||k>I-1) return 0;

	LinkList s;
	s=(LinkList)malloc(sizeof(LNode));

	if(s==NULL)

	{

		printf("ÉêÇëÊ§°Ü!");

		return ERROR;

	}

	s->data=e; s->next=p->next; p->next=s;

}//Insert

int ListDelete(LinkList &L,int I)

{

	LinkList p=L;

	int k=0;

	while(p&&k<I-1)

	{

		p=p->next;

		++k;

	}

	if(!p||k>I-1) return ERROR;

	LinkList s=(LinkList)malloc(sizeof(LNode));

	if(s==NULL);

	{

		printf("ÉêÇëÊ§°Ü!");

		return ERROR ;

	}

	LinkList q;

	q=p->next; p->next=q->next; 

	delete(q);	

}//Delete

void MergeList(LinkList &La,LinkList &Lb,LinkList &Lc)

{

	LinkList pa,pb,pc;

	pa=La->next; pb=Lb->next;

	Lc=pc=pa;

	while(pa&&pb) 

	{

		if(pa->data<=pb->data)

		{

			pc->next=pa;pc=pa;pa=pa->next; 

		}

		else

		{

			pc->next=pb;pc=pb;pb=pb->next;

		}

	}

	pc->next=pa?pa:pb;

	free(Lb);	

}//MergerList;

int main()

{

	ElemType e;

	LinkList La;

	CreateList(La,9);fflush(stdin); 

	int i;

	printf("ÊäÈë²åÈëÎ»ÖÃ¼°×Ö·û:");

	scanf("%d %c",&i,&e);

	ListInsert(La,i,e);

	Show(La);

	fflush(stdin);

	printf("\n");

	LinkList Lb;

    CreateList(Lb,9);

	int j;

	printf("ÊäÈëÉ¾³ıÎ»ÖÃ:");

	scanf("%d",&j);

	ListDelete(Lb,j);

	Show(Lb);

	fflush(stdin);

	printf("\n");

	printf("ÊäÈëĞèÒªºÏ²¢µÄ×Ö·û´®:");

	LinkList L1,L2,L3;

    CreateList(L1,4);

	Show(L1);

	fflush(stdin);

	CreateList(L2,4);

	Show(L2);

	MergeList(L1,L2,L3);

	Show(L3);

	return 0;

}

