#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef char type;
#define size 10
#define OVERFLOW 1
#define Increment 10



typedef struct {
	int ListLength;
	int ListSize;
	type* elem;
}SqList;



int InitList(SqList &L) {
	L.elem = (char*)malloc(size * sizeof(type));
	if (!L.elem)exit(OVERFLOW);
	L.ListSize = size;
	L.ListLength = 0;
	return 1;
}//DEFINE

int CreateList(SqList &L, type a[], int n) {
	int i;
	type *p = L.elem;
	for (i = 0; i<n; i++) {
		*p = a[i];
		p++;
	}
	L.ListLength = n;
	return 1;
}

int Showlist(SqList L) {
	int i;
	for (i = 0; i<L.ListLength; i++) {
		printf("%c ", L.elem[i]);
	}
	printf("\n");


}
int ListInsert(SqList &L, int i, type e) {
	while (i <= 0 || i>L.ListLength) return 0;
	if (L.ListLength>=L.ListSize) {
		type* New;
		New = (type*)realloc(L.elem, (L.ListSize + Increment) * sizeof(type));
		if (!New) exit(OVERFLOW);
		L.elem=New; 
		L.ListSize = L.ListSize + Increment;
	}
	type* p = L.elem + L.ListLength - 1;
	type* q = L.elem + i - 1;
	while (p >= q) {
		*(p + 1) = *p;
		p--;
	}
	*q = e;
	++L.ListLength;
	return 1;
}//INSERT

int ListDelete(SqList &L, int i) {
	type* p = &(L.elem[i - 1]);
	type* q = &(L.elem[L.ListLength - 1]);
	for (; p<q; p++) {
		*(p) = *(p + 1);
	}
	--L.ListLength;
	return 1;
}

int ListMerge(SqList La, SqList &L) {
	if (L.ListLength + La.ListLength>L.ListSize) {
		type* New;
		New = (type*)realloc(L.elem, (L.ListSize + Increment) * sizeof(type));
		if (!New) {
			exit(OVERFLOW);
			L.elem=New;
		L.ListSize = L.ListSize + Increment;
		}
	}
	int i = 0;
	while (i<La.ListLength){
		L.elem[L.ListLength+i]=La.elem[i];
		i++;
		}
		L.ListLength+=La.ListLength;
	return 1;
}
int SelectSort(SqList &L){
	int i;
	type a[L.ListLength];
	for(i=0;i<L.ListLength;i++){
		a[i]=L.elem[i];
	}
	type f=0;
	type tem;
	int k;
	int m;
	for(k=0;k<L.ListLength-1;++k){
		m=k;
	   for(i=k+1;i<L.ListLength;i++){
		if(a[i]<a[m]) m=i;		
    }
       f=m;
	if(f<L.ListLength&&f!=k){
		tem=a[k];
		a[k]=a[f];
		a[f]=tem;
	}		
}
	for(i=0;i<L.ListLength;i++){
		L.elem[i]=a[i];
	}
	return 1;
}


int main() {
	SqList List;
	SqList List_2;
	InitList(List);
	InitList(List_2);
	printf("please enter the array_1 :  ");
	type a[size];
	int x;
	for (x = 0; x<size; x++) {
		scanf("%c", &a[x]);	
	}fflush(stdin); 
	CreateList(List, a, size); 
	Showlist(List);
	int i;
	type p;
	printf("Please enter the elem to be inserted : ");
	scanf("%c", &p);
	printf("Please enter the location : ");
	scanf("%d", &i);
	ListInsert(List, i, p);
	printf("List_1 after insertion : ");
	Showlist(List);
	int k;
	printf("please enter the elem-location to be deleted : ");
	scanf("%d", &k);
	ListDelete(List, k);
	printf("List_1 after deletion : ");
	Showlist(List);
	printf("List Sorted : ");
	SelectSort(List);
	Showlist(List);
		printf("please enter the array 2 : ");
	type b[size];
	int y;fflush(stdin); 
	for (y = 0; y<size; y++) {
		scanf("%c", &b[y]);	
	}fflush(stdin); 
	CreateList(List_2, b, size); 
	printf("List_2 is : ");
	Showlist(List_2);
	SelectSort(List_2);
	printf("List_2 sorted : ");
	Showlist(List_2);
	printf("merged with List_2 : ");
	ListMerge(List_2, List);
	Showlist(List);


	return 0;
}
