class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> htab;
        for(int i = 0; i < nums.size(); i++){
            if(htab.find(nums[i]) != htab.end()) return true;
            htab.insert(nums[i]);
        }
        return false;   
    }
};