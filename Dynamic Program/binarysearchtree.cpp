/*optimal binary search tree*/

#include<iostream>
using namespace std;

const int n=5;
float e[n+1][n+1];
float w[n+1][n+1];
int root[n+1][n+1];

void opt_bst(float *p,float* q){
  for(int i = 1 ; i <= n+1 ; i++){
    e[i][i-1] = q[i-1];
    w[i][i-1] = q[i-1];
  }

  for(int k = 1;k <= n;k++){
    for(int i = 1;i <= n-k+1;i++){
      int j = i+k-1;
      w[i][j] = w[i][j-1]+p[j]+q[j];
      e[i][j] = e[i][i-1]+e[i+1][j]+w[i][j];
      for(int m = i; m <= j;m++){
        float t= e[i][m-1]+e[m+1][j]+w[i][j];
        if(t <= e[i][j]){
          e[i][j] = t;
          root[i][j] = m;
        }
      }
    }
  }
  // printtree(1,n);
  cout<<"expected cost  : "<< e[1][n];
}

int main(){
  float p[6]={0.00,0.15,0.10,0.05,0.10,0.20};
  float q[6]={0.05,0.10,0.05,0.05,0.05,0.10};
  opt_bst(p,q);
}
