/*find the k th smallest number*/

#include<iostream>
using namespace std;

int partition(int *a , int p, int r){
  if(p == r){return p;}
  else{
    int key = a[r];
    int m = p-1;
    for(int i = p; i<r; i++){
      if(a[i] <= key){
        m++;
        swap(a[m],a[i]);
      }
    }
    swap(a[r],a[m+1]);
    return m+1;
  }
}

int randomselect(int *a , int p ,int r, int k){
  if(p == r ){return a[p];}
  else{
    int i = partition(a,p,r);
    int n = i - p + 1;
    if(n > k){
      return randomselect(a,p,i-1,k);
    }
    else if(n < k){return randomselect(a,i+1,r,k-n);}
    else{return a[i];}
  }
}

int main(){
  int arr[10]={1,3,5,7,9,2,4,6,8,0};
  cout << randomselect(arr,0,9,3);
}
