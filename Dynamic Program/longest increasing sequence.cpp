/*longest sequence which is increasing*/

#include<iostream>
using namespace std;

//answer1 which costs n*n

int LIS(int *arr,int n){
  arr[0] = -1000;
  int m[100]={0};
  for(int i = 1; i <= n; i++){
    int max = 0;
    for(int j = i-1; j>=0 ;j--){
      int t = m[j]+(arr[j]<arr[i]?1:0);
      if(t>max){max =t;}
    }
    m[i] = max;
  }
  return m[n]-1;
}

int main(){
  int arr[9] = {1,-1,2,-2,3,-3,4,-4,5};
  cout << LIS(arr,9);
}


//answer 2 which costs nlogn
