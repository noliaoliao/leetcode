class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        if(nums.size() < 4) return ret;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size()-3; i++){
            //4元组过滤重复的情况
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1; j < nums.size()-2; j++){
                //3元组过滤重复的情况
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                int start = j+1;
                int end = nums.size()-1;
                int newtarget = target-(nums[i]+nums[j]);
                while(start < end){
                    if(nums[start]+nums[end] == newtarget){
                        vector<int> eachItem;
                        eachItem.push_back(nums[i]);
                        eachItem.push_back(nums[j]);
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
                    }else if(nums[start]+nums[end] > newtarget){
                        end--;
                    }else{
                        start++;
                    }
                }
            }
        }
        return ret;
    }
};