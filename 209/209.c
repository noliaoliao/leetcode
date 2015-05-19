int minSubArrayLen(int s, int* nums, int numsSize) {
    int nLeft = 0;     //������߽�
    int nRight = -1;   //�����ұ߽�
    int nTotal = 0;    //������ֵ��
    int nMinLen = numsSize+1;

    while(nRight < numsSize){
        while(nTotal < s && nRight < numsSize){
            nTotal += nums[++nRight];  //�һ���
        }
        if(nTotal >= s){
            if(nRight-nLeft+1 < nMinLen) nMinLen = nRight-nLeft+1;
            nTotal -= nums[nLeft++];   //�󻬶�
        }
    }

    return nMinLen > numsSize ? 0 : nMinLen;
}