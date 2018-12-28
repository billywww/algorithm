#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
int InitList(SqList &L);
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
	if (L.ListLength>L.ListSize) {
		type* New;
		New = (type*)realloc(L.elem, (L.ListSize + Increment) * sizeof(type));
		if (!New) exit(OVERFLOW);
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
		if (!L.elem) {
			exit(OVERFLOW);
		}
		L.ListSize = L.ListSize + Increment;
	}
	int i = 1;
	type*p = L.elem + L.ListLength - 1;
	type*q = La.elem;
	while (i++ <= 5) {
		*p++ = *q++;
	}
	L.ListLength = L.ListLength + La.ListLength;
	return 1;
}




char main() {
	SqList List;
	SqList List_2;
	InitList(List);
	InitList(List_2);
	type b[] = { 'a','a','a','a','a' };
	CreateList(List_2, b, 5);
	printf("please enter the array");
	type a[size];
	int x;
	for (x = 0; x<size; x++) {
		scanf("%c", &a[x]);
		fflush(stdin);
	}
	CreateList(List, a, size);
	Showlist(List);
	int i;
	type p;
	printf("Please enter the elem to be inserted");
	scanf("%c", &p);
	printf("Please enter the location");
	scanf("%d", &i);
	ListInsert(List, i, p);
	Showlist(List);
	int k;
	printf("please enter the elem-location to be deleted\n");
	scanf("%d", &k);
	ListDelete(List, k);
	Showlist(List);
	printf("List_2 is :");
	Showlist(List_2);
	printf("merged with List_2\n"); printf("%d\n", List.ListLength);
	ListMerge(List_2, List);
	printf("%d\n", List.ListSize);
	Showlist(List);


	return 0;
}