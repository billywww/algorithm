#include<stdio.h>

void sort(char* s){
    char mark[26][1000];
    int count[26]={0};
    char *p=s;
    while(*p){
      if(*p<65||*p>=123||(*p>=91&&*p<97)){}
      else{
        if(*p>=97){
          int t=(int)*p-97;
          mark[t][count[t]++]=*p;
        }
        else{
          int t=(int)*p-65;
          mark[t][count[t]++]=*p;
        }
      }
      p++;
    }
    char temp[1000];
    int i,j;
    int k=0;
    for(i=0;i<26;i++){
      for(j=0;j<count[i];j++){
        temp[k++]=mark[i][j];
      }
    }
    p=s;
    i=0;
    while(*p){
      if(*p<65||*p>=123||(*p>=91&&*p<97)){}
      else{
        *p=temp[i++];
      }
      p++;
    }
}

int main(){
  char str[1000];
  gets(str);
  sort(str);
  puts(str);
}
