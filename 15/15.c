class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        if(nums.size() < 3) return ret;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size()-2; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int start = i+1;
            int end = nums.size()-1;
            int target = -nums[i];
            while(start < end){
                if(nums[start]+nums[end] == target){
                    vector<int> eachItem;
                    eachItem.push_back(-target);
                    eachItem.push_back(nums[start]);
                    eachItem.push_back(nums[end]);
                    ret.push_back(eachItem);
                    //这里要防止后面的二元组出现重复的情况
                    int k = start+1;
                    while(k < end && nums[k] == nums[start]) k++;
                    start = k;

                    k = end - 1;
                    while(k > start && nums[k] == nums[end]) k--;
                    end = k;
                }else if(nums[start]+nums[end] > target){
                    end--;
                }else{
                    start++;
                }
            }
        }
        return ret;
    }
};