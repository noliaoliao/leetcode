int singleNumber(int* nums, int numsSize) {
    int ans = 0;
    //32位依次处理
    for(int i = 0; i < 32; i++){
        int count = 0;
        int offset = 1 << i;
        for(int j = 0; j < numsSize; j++){
            if(nums[j] & offset) count++;
        }
        //模3就是单个数对应的位
        if(count%3) ans |= offset;
    }

    return ans;
}