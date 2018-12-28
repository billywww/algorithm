#include<stdio.h>
#include<string.h> 
char* s_get(char*,int);
#define max 1000

struct book{
	char title[max];
	char author[max];
	float value;
}; 

int main(){
	struct book apple={
	"Apple Pie",
	"Wang",
	13.33
	};
	struct book array[max];
	array[0]=apple;
	int n=20;
	int i=1;
	int k;
	int flag;
    
	do
	{
		printf("enter the book\n");
        s_get(array[i].title,n);
        printf("author\n");
        s_get(array[i].author,n);
        printf("value\n");
        scanf("%f",&array[i].value);
        printf("1 to continue 0 to stop");
        scanf("%d",&flag);
        char ch;while((ch = getchar()) != '\n' && ch != EOF);
        i++;
    }while(flag);
    for(k=0;k<i;k++){
    	printf("%s by %s costs %.2f\n",array[k].title,array[k].author,array[k].value);
    }
    return 0;
}
char* s_get(char* st,int n){
	char* input;
	char* find;
	input=fgets(st,n,stdin);
	if(input){
		find=strchr(st,'\n');
		if(find){
			*find='\0';
		}
		else
		while(getchar()!='\n')
		continue;
		return input;
	}
}
