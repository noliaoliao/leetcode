int minSubArrayLen(int s, int* nums, int numsSize) {
    int nLeft = 0;     //窗口左边界
    int nRight = -1;   //窗口右边界
    int nTotal = 0;    //窗口数值和
    int nMinLen = numsSize+1;

    while(nRight < numsSize){
        while(nTotal < s && nRight < numsSize){
            nTotal += nums[++nRight];  //右滑动
        }
        if(nTotal >= s){
            if(nRight-nLeft+1 < nMinLen) nMinLen = nRight-nLeft+1;
            nTotal -= nums[nLeft++];   //左滑动
        }
    }

    return nMinLen > numsSize ? 0 : nMinLen;
}