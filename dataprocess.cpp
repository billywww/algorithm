#include<stdio.h>

int search(char* la,char* lb){
  int k=0;
  while(*la&&*lb){
    if(*la==*lb){
      k++;
      la++;
      lb++;
    }
    else{
      la-=k;
      lb-=k-1;
      k=0;
    }
  }
  if(!*la) return 1;
  else return 0;
}

int test(int a,int b){
  char stra[10],strb[10];
  sprintf(stra,"%d",a);
  sprintf(strb,"%d",b);
  return search(stra,strb);
}

int sort(int *a,int c){
  int i,j,k;
  int temp;
  for(i=1;i<c;i++){
    for(j=0;j<i;j++){
      if(a[j]>a[i]){
        temp=a[i];
        for(k=i-1;k>=j;k--){
          a[k+1]=a[k];
        }
        a[j]=temp;
        break;
      }
    }
  }
  for(i=1,k=0;i<c;i++){
    if(a[k]!=a[i]){
      a[k+1]=a[i];
      k++;
    }
  }
  return k+1;
}

int main(){
  int n1,n2;
  int i,j;
  int total=0;
  int R[100],T[100];
  int count[100]={0},mark[100][100];
  scanf("%d",&n1);
  for(i=0;i<n1;i++){
    scanf("%d",&R[i]);
  }
  scanf("%d",&n2);
  for(i=0;i<n2;i++){
    scanf("%d",&T[i]);
  }
  n2=sort(T,n2);
  for(i=0;i<n2;i++){
    for(j=0;j<n1;j++){
      if(test(T[i],R[j])){
        mark[i][count[i]]=j;
        count[i]++;
        total+=2;
      }
    }
  }
  for(i=0;i<n2;i++){
    if(count[i]!=0){
      total+=2;
    }
  }
  printf("%d",total);
  for(i=0;i<n2;i++){
    if(count[i]!=0){
      printf(" %d %d",T[i],count[i]);
      for(j=0;j<count[i];j++){
        printf(" %d %d",mark[i][j],R[mark[i][j]]);
      }
    }
  }
  return 0;
}
