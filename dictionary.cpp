#include<iostream>
#include<string.h>

int sort(char* a){
  char* p=a;
  int c=0;
  char temp;
  while(*p){
    c++;
    p++;
  }
  int i,j;
  for(i=c-1;i>0;i--){
    for(j=1;j<=i;j++){
      if(a[j-1]>a[j]){
        temp=a[j-1];
        a[j-1]=a[j];
        a[j]=temp;
      }
    }
  }
  return 1;
}

int bro(char* a,char *b){
  if(strcmp(a,b)){
  sort(a);
  sort(b);
  if(strcmp(a,b)){
    return 0;
  }else
  return 1;
 }
 else return 0;
}

int search(char* temp,char (*w)[50],int i){
  int count=0;
  int k=0;
  while(k<i){
    if(bro(temp,w[k])){
      count++;
    }
    k++;
  }
  return count;
}

int main(){
  int a;int num;
  while(std::cin>>a){
    int i=0;
    char word[1000][50];
    char temp[50];
    while(i<a){
      std::cin>>word[i];
      i++;
    }
    std::cin>>temp;
    std::cin>>num;
    std::cout<<search(temp,word,i);
  }
}
