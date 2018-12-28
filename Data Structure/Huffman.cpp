#include<stdio.h>

typedef struct Node{
	type  data;
	int weight;
	int lchild,rchild,parent;
}HuffNode;

int Hufftree(HuffNode* arr,int n){
	int i;
	int m=2n-1;
	int s1=-1,s2=-1;
	int j=n;
	while(j<2n-1){
	for(i=0;i<j;i++){
		if(!parent[i]){
			select(s1,s2);
		}
    }
    arr[s1].parent=j; arr[s2].parent=j;
    arr[j].lchild=s1; arr[j].rchild=s2;
    arr[j].weight=arr[s1].weight+arr[s2].weight;
    j++;
  }
  
}
