#include<stdio.h>
#include<stdlib.h>


double cal(int* nums1, int nums1Size, int* nums2, int nums2Size){

  //解法1： 合并两个有序数组，并找出中位数，复杂度:m+n

  //解法2：递归
  double median = 0.0;
  int left1;
  int left2;

  if(nums1Size == 0){
    if(nums2Size%2){median = nums2[nums2Size/2];}
    else if(nums2Size > 1){median = (nums2[nums2Size/2] + nums2[(nums2Size-1)/2]) / 2.0;}
    else{median = nums2[0];}
    return median;
  }

  if(nums2Size == 0){
    if(nums1Size%2){median = nums1[nums1Size/2];}
    else if(nums1Size > 1){median = (nums1[nums1Size/2] + nums1[(nums1Size-1)/2]) / 2.0;}
      else{median = nums1[0];}
    return median;
  }


  int l = 0;
  int r = nums1Size;
  int maxl, minr;
  while(l <= r){

    left1 = (l + r) / 2;
    left2 = (nums1Size + nums2Size + 1) / 2 - left1  ;

    if(nums2[left2-1] > nums1[left1] && left2 > 0 && left1 < nums1Size){
      l = left1+1;
    }
    else if(nums1[left1-1] > nums2[left2] && left1 > 0 && left2 < nums2Size){
      r = left1-1;
    }
    else{

      if(left1 == 0){
        maxl = nums2[left2 - 1];
      }
      else if(left2 == 0){
        maxl = nums1[left1 - 1];
      }
      else{
        maxl = (nums1[left1 - 1] > nums2[left2 - 1] ? nums1[left1 - 1] : nums2[left2 - 1]);
      }
      if((nums1Size + nums2Size) % 2){
          return maxl;
      }

      if(left2 == nums2Size){
        minr = nums1[left1];
      }
      else if(left1 == nums1Size){
        minr = nums2[left2];
      }
      else {
        minr = nums1[left1] < nums2[left2] ? nums1[left1] : nums2[left2];
      }
      if(left2 == nums2Size){
        minr = nums1[left1];
      }
      else if(left1 == nums1Size){
        minr = nums2[left2];
      }
      else {
        minr =( nums1[left1] < nums2[left2] ? nums1[left1] : nums2[left2]);
      }

      median = (maxl + minr) / 2.0;
      break;

      }

  }
    return median;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {

    if(nums1Size>nums2Size){
        return cal( nums2,  nums2Size, nums1,  nums1Size);
    }
    else{
        return cal( nums1,  nums1Size,  nums2,  nums2Size);
    }

}
