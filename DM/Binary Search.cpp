/*
二分搜索
*/

#include<iostream>

int binarysearch(int *a,int l,int r,int key){
  while(l <= r){
    int mid = (l + r)/2;
    if(key > a[mid]){
      l = mid + 1;
    }
    else if(key < a[mid]){
      r = mid - 1;
    }
    else{
      return mid+1;
    }
  }
  return 0;
}

int main(){
  int arr[10] = {0,1,2,3,4,5,6,7,8,9};
  int r = binarysearch(arr,0,9,5);
  std::cout << r ;
  return 0;
}
