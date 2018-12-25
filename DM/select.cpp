#include<stdio.h>
int go(int x,int n){
	static int a[100];
	static int i=0;
	int t;
	if(x<n){
		t=2*x+1;
		a[i++]=1;
		go(t,n);
		t=2*x+2;
		a[i++]=2;
		go(t,n);
		a[--i]=0;
	}
	if(x>n){
		a[--i]=0;
	}
	if(x==n){
		a[i]='\0';
		i=0;
		while(a[i]!='\0'){
			printf("%d",a[i++]);
		}
		return 1;
	}
}
int main(){
	int x;
	int n;
	scanf("%d %d",&x,&n);
	go(x,n);
	return 0;
}
