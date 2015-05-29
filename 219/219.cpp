class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> hashmap;
        unordered_map<int,int>::iterator it;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            it = hashmap.find(nums[i]);
            if(it != hashmap.end()){
                if(i - it->second <= k) count++;
            }
            hashmap[nums[i]] = i;
        }

        return count == 1;
    }
};