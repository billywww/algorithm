/* Leetcoe 45: Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example:

Input: [2,3,1,1,4]
Output: 2

Explanation: The minimum number of jumps to reach the last index is 2.
Jump 1 step from index 0 to 1, then 3 steps to the last index.*/

int jump(int* nums, int numsSize) {
    int cur = 0;
    int expect = 0;
    int f;
    while(cur < numsSize-1){
        int max = 0;
        for(int i = cur+1;i <= cur+nums[cur]&&i<numsSize;i++){

             if(i == numsSize-1){     //当前while循环就能达到终点
                f = i;
                break;
            }

            int temp = i+nums[i];   //下一个while循环能达到的最远点

            if(temp>max){
                f = i;
                max = temp;
            }
        }
        cur = f;
        expect++;
    }
    return expect;
}
