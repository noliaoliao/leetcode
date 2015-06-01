class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() <= 1) return 0;

        //遍历一遍找到最大最小值
        int nMaxNum = nums[0];
        int nMinNum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nMaxNum) nMaxNum = nums[i];
            if(nums[i] < nMinNum) nMinNum = nums[i];
        }

        int nBucketSize = (nMaxNum - nMinNum)/nums.size()+1;   //每个桶的大小,向上取整
        int nBucketNums = (nMaxNum - nMinNum)/nBucketSize+1;   //桶的数量
        vector<vector<int>> buckets(nBucketNums);
        for(int i = 0; i < nums.size(); i++){
            //每个元素都入桶,每个桶里只保存这桶的最大值和最小值
            //单个桶内,最大的gap就是nBucketSize-1,而桶的数量为nums.size+1
            //必有一个空桶,因为最大的gap一定是在两个连续桶之间
            int index = (nums[i]-nMinNum)/nBucketSize;
            if(buckets[index].empty()){
                buckets[index].reserve(2);
                buckets[index].push_back(nums[i]);
                buckets[index].push_back(nums[i]);
            }else{
                if(nums[i] < buckets[index][0]){
                    buckets[index][0] = nums[i];
                }
                if(nums[i] > buckets[index][1]){
                    buckets[index][1] = nums[i];
                }
            }
        }

        int nMaxGap = INT_MIN;
        int nPreBucket = 0;
        for(int i = 1; i < buckets.size(); i++){
            if(buckets[i].empty()) continue;
            if(buckets[i][0] - buckets[nPreBucket][1] > nMaxGap){
                nMaxGap = buckets[i][0] - buckets[nPreBucket][1];
            }
            nPreBucket = i;
        }

        return nMaxGap;
    }
};