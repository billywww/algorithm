/*leetcode 215 : Find the kth largest element in an unsorted array.
Note that it is the kth largest element in the sorted order,
 not the kth distinct element*/


 /*answer 2 with heap*/
#include<algorithm>

void shiftdown(int * arr,int n,int num){
  int cur = n;
  while(2*cur+1<=num){
    int l = 2*cur+1;
    int r = 2*cur+2;
    int temp = arr[cur]>arr[l]?cur:l;
    if(r<=num&&arr[temp]<arr[r])
      temp = r;
    if(cur!=temp){
      std::swap(arr[cur],arr[temp]);
      cur = temp;
    }
    else break;
  }
}

int findKthLargest(int* nums, int numsSize, int k) {
  for(int i=numsSize;i>=0;i--){
    shiftdown(nums,i,numsSize-1);
  }
  for(int i = 0;i<k-1;i++){
    nums[0] = nums[numsSize-1];
    numsSize--;
    shiftdown(nums,0,numsSize-1);
  }
  return nums[0];
}
