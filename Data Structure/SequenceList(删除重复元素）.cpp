#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef int type;
#define Isize 10

typedef struct{
	type* elem;
	int length;
	int size;
}SqList;
 
void initlist(SqList &L ){
	L.elem=(type*)malloc(Isize*sizeof(type));
	L.length=0;
	L.size=Isize;
} 

void createlist(SqList &L,type n){
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&L.elem[i]);
		L.length++;
	}	
}

void differ(SqList &L){
	int i,j,k;
	j=1;
	for(i=0;i<L.length-1;i++,j=i+1){
		while(j<L.length&&L.elem[i]!=L.elem[j]){
			j++;
		}
		if(j!=L.length){
			k=i;
			while(k<L.length-1){
				L.elem[k]=L.elem[k+1];
				k++;
			}
			i--;
			L.length-=1;
		}
			
	}	
}


void showlist(SqList L){
	int i;
	for(i=0;i<L.length;i++){
		printf("%d",L.elem[i]);
	}
	printf("\n");	
}


int main(){
	SqList List;
	initlist(List);
	int n=6;
	printf("enter 6 numbers\n");
	createlist(List,n);
	showlist(List);
	differ(List);
	showlist(List);
	return 0;	
}
