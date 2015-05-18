bool canJump(int* nums, int numsSize) {
    int* htab1 = (int *)malloc(sizeof(int)*numsSize);  //标记是否可达
    int* htab2 = (int *)malloc(sizeof(int)*numsSize);  //标记是否需要判断
    memset(htab1,0,sizeof(int)*numsSize);
    memset(htab2,0,sizeof(int)*numsSize);
    htab1[0] = 1;
    for(int i = 0; i < numsSize-1; i++){
        if(htab2[i] == 1) continue;
        if(htab1[i] == 1){
            int nMaxJump = nums[i];
            int nBegin = i;
            for(int j = 1; j < nMaxJump+1 && j+nBegin < numsSize; j++){
                htab1[i+j] = 1;
                //如果nums[i+j] <= nums[nBegin]-j,说明i+j位置是不需要遍历的
                //因为他能走的情况,nums[nBegin]已经走过了
                if(nums[i+j] <= nums[nBegin]-j) htab2[i+j] = 1;
            }
        }
    }
    return htab1[numsSize-1] == 1 ? true : false;
}