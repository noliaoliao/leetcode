class Solution {
public:
    void getCombinationSum(vector<int>& nums, int k, int target, int start, vector<vector<int>>& allItem, vector<int> eachItem){
        if(target == 0 && eachItem.size() == k){
            allItem.push_back(eachItem);
            return;
        }else{
            for(int i = start; i < nums.size(); i++){
                //这里要处理下重复的情况
                if(i > start && nums[i] == nums[i-1]) continue;
                //因为nums是排序的,因此碰到一个和大于target的情况时,剩下的就不用往ecahItem添加了
                //这样能减少回溯的次数
                if(nums[i] > target) break; 
                target -= nums[i];
                eachItem.push_back(nums[i]);
                getCombinationSum(nums,k,target,i+1,allItem,eachItem);
                //做回溯的处理,恢复target和eachItem
                target += nums[i];
                eachItem.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        int nums[] = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>> allItem;
        vector<int> eachItem;
        vector<int> candidates(nums,nums+9);
        getCombinationSum(candidates,k,n,0,allItem,eachItem);
        return allItem;
    }
};