/*leetcode 215 : Find the kth largest element in an unsorted array.
Note that it is the kth largest element in the sorted order,
 not the kth distinct element*/

/*answer 1:  use randompartation in quick sort*/
int findKthLargest(int* nums, int numsSize, int k) {
    if(numsSize == 1)
        return nums[0];
    else{
        int i = randompart(nums,numsSize);
        if(k>i)
            return findKthLargest(nums+i,numsSize-i,k-i);
        else
            return findKthLargest(nums,i,k);
    }

}

int randompart(int *nums,int n){
    int end = n-1;
    int cur = -1;
    for(int i = 0;i < end; i++){
        if(nums[i]>=nums[end]){

            int temp = nums[i];
            nums[i] = nums[cur+1];
            nums[cur+1] = temp;

            cur++;
        }
    }

    int temp = nums[end];
    nums[end] = nums[cur+1];
    nums[cur+1] = temp;

    return cur+1;
}
