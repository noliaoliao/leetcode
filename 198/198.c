/*简单的动态规划*/
int rob(int* nums, int numsSize) {
    if(numsSize == 0 || nums == NULL) return 0;
    if(numsSize == 1) return nums[0];
    if(numsSize == 2) return nums[0] > nums[1] ? nums[0] : nums[1];
    int *maxMoney = (int *)malloc(sizeof(int)*numsSize);
    maxMoney[0] = nums[0];
    maxMoney[1] = nums[0] > nums[1] ? nums[0] : nums[1];
    for(int i = 2; i < numsSize; i++){
        //偷不偷这个房子,做下比较,取最大值即可
        if(nums[i]+maxMoney[i-2] > maxMoney[i-1]){
            maxMoney[i] = nums[i]+maxMoney[i-2];
        }else{
            maxMoney[i] = maxMoney[i-1];
        }
    }
    
    return maxMoney[numsSize-1];
}