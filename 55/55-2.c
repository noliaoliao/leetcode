bool canJump(int* nums, int numsSize) {
    if(numsSize <= 1) return true;
    int nMaxLen = nums[0];
    
    for(int i = 0; i < numsSize - 1; i++){
        //如果最大距离超过长度,true
        if(nMaxLen >= i && i+nums[i] >= numsSize-1) return true;
        //如果最大距离达到不了当前的点,并且当前点不能往前跳(==0),false
        if(nMaxLen <= i && nums[i] == 0) return false;
        //更新最大距离
        if(i + nums[i] > nMaxLen) nMaxLen = i + nums[i];
    }
    
    return false;
}