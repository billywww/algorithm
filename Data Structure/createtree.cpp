#include<stdio.h>
#include<stdlib.h>
typedef struct BiT{
	char data;
	struct BiT *lchild;
	struct BiT *rchild;
}BiT;

BiT* CreateBiTree(BiT *T){
	char ch;
	scanf("%c", &ch);
	if(ch==' ') T=NULL;
	else{
	T=(BiT*)malloc(sizeof(BiT));
	T->data=ch;
	T->lchild=CreateBiTree(T->lchild);
	T->rchild=CreateBiTree(T->rchild);
	}
	
	return T;
}

int PreOrderTraverse(BiT *T,int &n){
	//�������������T
	int t=0;
	if(T){
		printf("%c", T->data);  
		if(!PreOrderTraverse(T->lchild,n)) t++;
		if(!PreOrderTraverse(T->rchild,n)) t++;
		if(t==2) n++;
		return 1;
	} 
	return 0;
}


int main(){
	int n=0;
	printf("��������");
	BiT *T=CreateBiTree(T);
	printf("\n���������");
	PreOrderTraverse(T,n);
	printf("\nҶ�ӽ�� ��%d",n);
	
	getchar();getchar(); 
	return 0;
}

