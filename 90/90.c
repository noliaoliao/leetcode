//子集问题,简单的回溯处理
//元素有重复,这并不影响,代码和subsets一样
class Solution {
public:
    void getAllSubsets(vector<int>& nums, int start, vector<vector<int>>& allSubsets, vector<int> eachSubset){
        allSubsets.push_back(eachSubset); 
        for(int i = start; i < nums.size(); i++){
            if(i > start && nums[i] == nums[i-1]) continue;
            eachSubset.push_back(nums[i]);
            getAllSubsets(nums,i+1,allSubsets,eachSubset);
            eachSubset.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allItem;
        vector<int> eachItem;
        if(nums.size() != 0){ 
            sort(nums.begin(),nums.end());
            getAllSubsets(nums,0,allItem,eachItem);
        }
        return allItem;
    }
};