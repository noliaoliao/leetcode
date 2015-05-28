int rob2(int* nums, int left, int right) {
    if(right - left <= 1) return nums[left];

    int *maxMoney = (int *)malloc(sizeof(int)*right);
    maxMoney[left] = nums[left];
    maxMoney[left+1] = nums[left] > nums[left+1] ? nums[left] : nums[left+1];

    for(int i = left+2; i < right; i++){
        if(nums[i]+maxMoney[i-2] > maxMoney[i-1]){
            maxMoney[i] = nums[i]+maxMoney[i-2];
        }else{
            maxMoney[i] = maxMoney[i-1];
        }
    }

    return maxMoney[right-1];
}

int rob(int* nums, int numsSize) {
    if(nums == NULL || numsSize <= 0) return 0;
    if(numsSize == 1) return nums[0];
    
    int nMaxHead = rob2(nums,0,numsSize-1);  //不抢尾部的房子
    int nMaxTail = rob2(nums,1,numsSize);    //不抢头部的房子

    return nMaxHead > nMaxTail ? nMaxHead : nMaxTail;
}