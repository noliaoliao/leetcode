int jump(int* nums, int numsSize) {
    //这3个标记数组其实是可以合并,减少空间占用
    int* htab1 = (int *)malloc(sizeof(int)*numsSize);  //标记是否可达
    int* htab2 = (int *)malloc(sizeof(int)*numsSize);  //标记是否需要判断
    int* htab3 = (int *)malloc(sizeof(int)*numsSize);  //标记最小步数
    memset(htab1,0,sizeof(int)*numsSize);
    memset(htab2,0,sizeof(int)*numsSize);
    memset(htab3,0,sizeof(int)*numsSize);
    htab1[0] = 1;
    for(int i = 0; i < numsSize-1; i++){
        if(htab2[i] == 1) continue;
        if(htab1[i] == 1){
            int nMaxJump = nums[i];
            int nBegin = i;
            int nJumps = htab3[i];   //当前起始点的最小跳数
            for(int j = 1; j < nMaxJump+1 && j+nBegin < numsSize; j++){
                htab1[i+j] = 1;
                if(nums[i+j] <= nums[nBegin]-j) htab2[i+j] = 1;
                //之前没有到达过,则上一步跳数+1
                //已经达到过了,那之前的肯定是最小跳数
                if(htab3[i+j] == 0){
                    htab3[i+j] = nJumps+1;
                }
            }
        }
    }
    return htab3[numsSize-1]; 
}