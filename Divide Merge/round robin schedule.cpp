/*
n = 2^k players will take part in a match
every player must play with each other
*/

#include<iostream>

int t[100][100];

void merge(int l,int m,int r){
  int k = r-m;
  for(int i = l;i<=m;i++){
    for(int j = k;j<2*k;j++){
      t[i][j] = t[i+k][j-k];
    }
  }
  for(int i = m+1;i<=r;i++){
    for(int j = k;j<2*k;j++){
      t[i][j] = t[i-k][j-k];
    }
  }
}

void schedule(int l,int r){
  if(r > l){
    int m = (r + l)/2;
    schedule(l,m);
    schedule(m+1,r);
    merge(l,m,r);
  }
}

int main(){
  int n;
  std::cin >> n;
  for(int i = 0;i<n;i++){
    t[i][0] = i;
  }
  schedule(0,n-1);
  for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++){
      std::cout<<t[i][j];
    }
    std::cout<<std::endl;
  }
}
