class Solution {
public:
   int threeSumClosest(vector<int>& nums, int target) {
        int nSize = nums.size();
        int nMin = INT_MAX;
        int nDif = INT_MAX;
        if(nSize < 3) return 0;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nSize-2; i++){
            int start = i+1;
            int end = nSize-1;
            int newtarget = target-nums[i];
            while(start < end){
                if(nums[start]+nums[end] == newtarget){
                    return target;
                }else if(nums[start]+nums[end] > newtarget){
                    if(abs(nums[start]+nums[end]+nums[i]-target) < nDif){
                        nDif = abs(nums[start]+nums[end]+nums[i]-target);
                        nMin = nums[start]+nums[end]+nums[i];
                    }
                    end--;
                }else{
                    if(abs(nums[start]+nums[end]+nums[i]-target) < nDif){
                        nDif = abs(nums[start]+nums[end]+nums[i]-target);
                        nMin = nums[start]+nums[end]+nums[i];
                    }
                    start++;
                }
            }
        }
        return nMin;
    }
};