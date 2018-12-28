#include<stdio.h>
#include<string.h>
char* s_get(char*,int);
#define max 40

struct book{
	char title[max];
	char author[max];
	float value;
};

int main(){
    book exam;
    printf("Please enter the title\n");
    s_get(exam.title,max);
    printf("Please enter the author\n");
    s_get(exam.author,max);
    printf("Please enter the value\n");
    scanf("%f",&exam.value);
    printf("%s by %s :%.2f\n",exam.title,exam.author,exam.value);
    return 0;
}

char* s_get(char* st,int n){
	char* input;
	char* find;
	input=fgets(st,n,stdin);
	while(input){
		find=strchr(st,'\n');
		if(strchr(st,'\n')){
			*find='\0';
		}
		return input;
	}
	
}
