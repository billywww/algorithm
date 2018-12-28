/*convert int*/
#include<stdio.h>
int convert(int a,int n){
	int t=a%n;
	int k=a/n;
	printf("%d",t);
	if(k)
	convert(a/n,n);
	return 1;
}
int main(){
	int a,n;
	scanf("%d %d",&a,&n);
	convert(a,n);
	return 0;
}
