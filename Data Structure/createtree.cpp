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
	//先序遍历二叉树T
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
	printf("先序建树：");
	BiT *T=CreateBiTree(T);
	printf("\n先序遍历：");
	PreOrderTraverse(T,n);
	printf("\n叶子结点 ：%d",n);
	
	getchar();getchar(); 
	return 0;
}

