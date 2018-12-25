#include<iostream>

int partition(int *a,int l,int r){
  int key = a[r];
  int m = l-1;

  for(int i = l; i<r; i++){
    if (a[i] <= key){
      m++;
      std::swap(a[m],a[i]);
    }
  }
  std::swap(a[r],a[m+1]);
  return m+1;
}

void quicksort(int *a,int l,int r){
  if(l < r){
    int q = partition(a,l,r);
    quicksort(a, l, q-1);
    quicksort(a, q+1, r);
  }
}
int main() {
  int arr[10] = {2,3,5,4,1,8,7,6,9,0};
  quicksort(arr,0,5);
  for(int i = 0 ;i < 6;i++){
    std::cout<<arr[i]<<"";
  }
}
