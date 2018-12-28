//multiple several arrays with least cost

#include<iostream>

using namespace std;

void matrixchain(int *p,int n,int(*m)[100],int(*s)[100]){
  for(int i = 0;i < n;i++){m[i][i]=0;}

  for(int r = 1;r < n; r++){
    for(int i = 0;i < n-r;i++){
      int j = i+r;
      m[i][j] = m[i][i]+m[i+1][j]+p[2*i]*p[2*i+1]*p[2*j+1];
      for(int k = i ;k < j;k++){
        int t = m[i][k]+m[k+1][j]+p[2*i]*p[2*k+2]*p[2*j+1];
        if(t <= m[i][j]){
          m[i][j] = t;
          s[i][j] = k+1;
        }
      }
    }
  }
}

int main(){
  int arr[100][100]={0};
  int res[100][100]={0};
  int p[12]={30,35,35,15,15,5,5,10,10,20,20,25};
  matrixchain(p,6,arr,res);
  for(int i=0;i<6;i++){
    for(int j=0;j<6;j++){
      cout<<arr[i][j]<<"     ";
    }
    cout<<endl;
  }
  cout<<endl;
  for(int i=0;i<6;i++){
    for(int j=0;j<6;j++){
      cout<<res[i][j]<<"     ";
    }
    cout<<endl;
  }
}
