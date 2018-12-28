#include<stdio.h>
#include<malloc.h>
typedef char type;
#define max 20

typedef struct {
	type data;
	int cur;
}component,LNode[max];


int Initlist (LNode &L){
	int i;
	for(i=0;i<max-1;i++){
		L[i].cur=i+1;
	}
	L[max-1].cur=0;
	return 1;
} 


int malloc(LNode &L){
	int k;
	k=L[0].cur;
	if(k){
		L[0].cur=L[k].cur;
	}
	return k;
} 


void Free(LNode &L,int i){
	L[i].cur=L[0].cur; 
	L[0].cur=i;	
}

void Createlist(LNode &L,int n){
	int i=1;
	int k=1;
	int r;
	r=max-1;
	while(k++<=n){
		i=malloc(L);
		scanf("%c",&L[i].data);
		L[r].cur=i;
		r=i; 
	}
	L[i].cur=0;
	fflush(stdin);
}


void Listdelete(LNode &L,int i,type &e){
	int k,j;
	j=1;
	k=L[max-1].cur;

	while(k&&j<i-1){
		j++;
		k=L[k].cur;
	}
	j=L[k].cur;
	L[k].cur=L[j].cur;
	Free(L,j);	

}


void Listinsert(LNode &L,int i,type e){
	int k;
	k=malloc(L);
	L[k].data=e;
	int j;
	int n=1;
	j=L[max-1].cur;
	while(j&&n<i-1){
		n++;
		j=L[j].cur;
	}
	L[k].cur=L[j].cur;
	L[j].cur=k;
}


int Getelem(LNode L,type e){
	int k;
	int i=0;
	k=L[max-1].cur;
	while(k){
		i++;
		if(L[k].data==e) return i;
		k=L[k].cur;
	}
	return 0;
}

void Differ(LNode &La,LNode &Lb){
	int f;
	type r;
	int i;
	for(i=La[max-1].cur;i!=0;i=La[i].cur){
		
		f=Getelem(Lb,La[i].data);
		if(f) 
		Listdelete(Lb,1,r);
		if(!f) Listinsert(Lb,1,La[i].data);
	}
}

void Showlist(LNode L){
	int i;
	i=L[max-1].cur;
	while(i){
		printf("%c",L[i].data);
		i=L[i].cur;
	}	
	printf("\n");
}

int main(){
	LNode List1,List2,List3;
	Initlist (List1);
	Createlist(List1,6);
	Showlist(List1);
	Initlist (List2);
	Createlist(List2,4);
	Showlist(List2);
	Differ(List1,List2);
	Showlist(List2);
	return 0;
}
