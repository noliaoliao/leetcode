class Solution {
public:
    void getCombinationSum(vector<int>& nums, int target, int start, vector<vector<int>>& allItem, vector<int> eachItem){
        if(target == 0){
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
                //和Combination Sum I的区别是每个数字只能用一次,该下每次的开始值就行了
                //注意i和i+1
                getCombinationSum(nums,target,i+1,allItem,eachItem);
                //做回溯的处理,恢复target和eachItem
                target += nums[i];
                eachItem.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> allItem;
        vector<int> eachItem;
        if(candidates.size() != 0){ 
            sort(candidates.begin(),candidates.end());
            getCombinationSum(candidates,target,0,allItem,eachItem);
        }
        return allItem;
    }
};