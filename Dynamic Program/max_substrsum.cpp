/*max sub str whose sum is max*/

#include<iostream>
using namespace std;

//answer 1 dynamic method

int maxsub(int *a,int n){
  int maxsum=0;
  int sum = 0;
  for(int i=0;i<n;i++){
    sum+=a[i];
    if(sum>maxsum){
      maxsum=sum;
    }
    if(sum > 0){

    }
    else{
      sum = 0;
    }
  }
  return maxsum;
}

int main(){
  int a[6]={-2,11,-4,13,-5,-2};
  cout<<maxsub(a,5);
}
