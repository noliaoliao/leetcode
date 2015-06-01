class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() <= 1) return 0;
        //快排后扫描一遍即可得出maxgap,一般解法
        sort(nums.begin(),nums.end());
        int nMaxGap = INT_MIN;
        int nCurGap = 0;
        for(int i = 1; i < nums.size(); i++){
            nCurGap = nums[i]-nums[i-1];
            if(nCurGap > nMaxGap) nMaxGap = nCurGap;
        }
        return nMaxGap;
    }
};