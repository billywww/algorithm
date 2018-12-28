/*max substr whose sum is maxmium*/

#include<iostream>
using namespace std;

//answer2: recursion

int maxsub(int *a,int l,int r){
  if(l == r){return a[l];}
  else{
    int k = (l+r)/2;
    int leftsum = maxsub(a,l,k);
    int rightsum = maxsub(a,k+1,r);
    int m = 0;
    int n = 0;
    int temp = 0;
    for(int i = k;i>=0;i--){
      temp +=a[i];
      if(temp > m){
        m = temp;
      }
    }
    temp = 0;
    for(int i = k+1;i <=r;i++){
      temp +=a[i];
      if(temp > n){
        n = temp;
      }
    }
    m += n;
    if(leftsum<m&&rightsum<m){return m;}
    else if(leftsum>rightsum){return leftsum;}
    else{return rightsum;}
  }
}
int main(){
  int a[6]={-2,11,-4,13,-5,-2};
  cout<<maxsub(a,0,5);
}
