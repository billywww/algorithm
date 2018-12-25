
#include<iostream>
using namespace std;

int maxsum(int *a,int m,int n){
  int max = 0;
  int b[100] ={0};
  for(int i=m;i<=n;i++){
    b[i] = (b[i-1]+a[i])>a[i]?(b[i-1]+a[i]):a[i];
    if(b[i]>max){
      max = b[i];
    }
  }
  return max;
}

int maxarrsum(int (*a)[5],int m,int n){
  int sum = 0;
  int max = 0;
  for(int i = 0;i<m;i++){
    for(int j = i;j<m;j++){
      int b[100] = {0};
      for(int k = 0;k<n;k++){
        for(int s = i;s<=j;s++){
          b[k]+=a[s][k];
        }
      }
      sum = maxsum(b,0,n-1);
      if(sum>max){max = sum;}
    }
  }
  return max;
}

int main(){
  int a[5][5]={{-1,2,1,-2,-1},{-1,2,1,-2,-1},{-1,2,1,-2,-1},{-1,-2,1,-2,-1},{-1,-2,1,-2,-1}};
  cout<<maxarrsum(a,5,5);
}
