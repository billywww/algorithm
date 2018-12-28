#include<stdio.h>
#define max 2
typedef struct {
	char name[10];
	int num;
	float grade;
	int age;
	char sex;
}stu;

int main(){
	stu S[max];
	float g[max];
	int i,j;
	stu tem;
	for(i=0;i<max;i++){
		scanf("%d%s%d%f %c",&S[i].num,S[i].name,&S[i].age,&S[i].grade,&S[i].sex);
		g[i]=S[i].grade;fflush(stdin);
	}
		for(i=0;i<max;i++){
		printf("%d %s %c %d %.2f",S[i].num,S[i].name,S[i].sex,S[i].age,S[i].grade);
	}
	for(i=0;i<max-1;i++){
		for(j=0;j<max-1-i;j++){
			if(g[j+1]<g[j]){
				tem=S[j];
				S[j]=S[j+1];
				S[j+1]=tem;
			}
		}
		
	}
	for(i=0;i<max;i++){
		printf("%d %s %c %d %.2f",S[i].num,S[i].name,S[i].sex,S[i].age,S[i].grade);
	}
	return 0;
}
