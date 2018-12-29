#include<iostream>

void quick_sort(int *,int ,int );

void optimalpack(int *weight,int n,int max_weight,bool* mark){
  quick_sort(weight,0,n-1);
  int current_weight = 0;
  int c = 0;
  while(c <= n && current_weight + weight[c] <= max_weight){
    mark[c] = true;
    current_weight += weight[c];
    c++;
  }
}

int partition(int *arr,int l,int r){
  int temp = arr[r];
  int mid = l-1;

  for(int i = l;i < r;i++){
    if(arr[i] < temp){
      std::swap(arr[i],arr[mid+1]);
      mid++;
    }
  }
  std::swap(arr[r],arr[mid+1]);
  return mid+1;
}

void quick_sort(int *arr,int l,int r){
  if(l<r){
    int q = partition(arr,l,r);
    quick_sort(arr,l,q-1);
    quick_sort(arr,q+1,r);
  }
}

int main(){
  int arr[]={8,2,3,1,3,4,3,2,1,8};
  const int n = 10;
  const int max_weight = 6;
  bool mark[n] = {0};
  optimalpack(arr,n,max_weight,mark);
  for(int i =0;i<n;i++){
    if(mark[i])
      std::cout<<arr[i]<<' ';
  }
}
