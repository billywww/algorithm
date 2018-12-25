#include<iostream>
using namespace std;

int m[100][100]={0};

int maxsum(int *a,int e,int n){
  int res=0;
  for(int i=1;i<=e;i++){
    for(int j=i;j<=n;j++){
      if(i<j)
      {int max = m[i][j-1]+a[j];
      for(int k = j-1;k>=i-1;k--){
        int temp = m[i-1][k]+a[j];
        if(temp > max){
          max = temp;
        }
      }
      m[i][j] = max;}
      else{
        m[i][j] = m[i-1][j-1]+a[j];
      }
    }
  }

  for(int i = e;i<=n;i++){
    if(m[e][i]>res){
      res =m[e][i];
    }
  }
  return res;
}

int main(){
  int a[7]={0,-2,11,-4,13,-5,-2};
  cout<<maxsum(a,6,6);
}
